#include <iostream>
#include <Windows.h>
#include <string>
#include <limits>

//Ó÷åòíûå çàïèñè
bool isAdmin = false;
int userCount = 2;
std::string* loginArr = new std::string[userCount]{ "admin", "user" };
std::string* passwordArr = new std::string[userCount]{ "admin", "user" };
//----------------------


//ñêëàä
int size = 10;
int* idArr = new int[size];
int* countArr = new int[size];
double* priceArr = new double[size];
std::string* nameArr = new std::string[size];

//----------------------
//ôóíêöèè
void Start();
bool Login();
void ShopUserMenu();
void ShopAdminMenu();
void CreateStaticStorage();
void ShowStorage();

template<typename ArrType>
void SetArr(ArrType staticArr, ArrType dynamicArr, int size);

template<typename ArrType>
void PrintArr(ArrType dynamicArr, int size);

#if defined(max)
#undef max
#endif


int main()
{
	Start();
	delete[]loginArr;
	delete[]passwordArr;
	delete[] idArr;
	delete[] countArr;
	delete[] nameArr;
	return 0;
}

void Start()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	std::cout << "\n\n\t\tГрелка\n\n\n";
	if (Login() == true)
	{
		//std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		
		if (isAdmin == true)
		{
			std::string choose;
			do
			{

			
			std::cout << "Использовать готовый склад или создать новый?\n";
			std::cout << "1 - Готовый склад\n2 - Создать новый\n\nВвод: ";
			std::getline(std::cin, choose, '\n');
			} while (choose.size() > 1 || choose[0] < 49 || choose[0] > 50);

			if (choose == "1")
			{
				CreateStaticStorage();
			}
			else
			{

			}
			ShopAdminMenu();
		}
		else
		{
			CreateStaticStorage();
			ShopUserMenu();
		}
			
		
	}
}

bool Login()
{
	while (true)
	{
		std::string login, pass;
		std::cout << "Введите логин: ";
		std::getline(std::cin, login, '\n');
		std::cout << "Введите пароль: ";
		std::getline(std::cin, pass, '\n');

		for (int i = 1; i < userCount; i++)
		{
			if (login == loginArr[0] && pass == passwordArr[0])
			{
				std::cout << "Добро пожаловать! " << loginArr[0] << '\n';
				isAdmin = true;
				return true;
			}

			else if (login == loginArr[i] && pass == passwordArr[i])
			{
				std::cout << "Добро пожаловать! " << loginArr[i] << '\n';
				isAdmin = false;
				return true;
			}
		}
		system("cls");
		std::cout << "Вы неверно ввели данные!\n\n";
	}
	return true;
}

void ShopUserMenu()
{
	std::cout << "User";

}

void ShopAdminMenu()
{
	std::string choose{};
	while (true)
	{
		do
		{
			std::cout << "1. Íà÷àòü ïðîäàæó\n";
			std::cout << "2. Показать склад\n";
			std::cout << "3. Ïîïîëíèòü ñêëàä\n";
			std::cout << "4. Ñïèñàòü ñêëàä\n";
			std::cout << "5. Èçìåíèòü öåíó\n";
			std::cout << "6. Èçìåíèòü ñêëàä\n";
			std::cout << "7. Èçìåíèòü ïåðñîíàë\n";
			std::cout << "8. Îò÷åò î ïðèáûëè\n\n";
			std::cout << "0. Çàêðûòü ñìåíó\n\n\n";
			// äîáàâëåíèå àêöèè 
			std::cout << "Ââîä: ";
			std::getline(std::cin, choose, '\n');
		} while (choose.size() > 1 || choose[0] < 48 || choose[0] > 56); //ïðîìåæóòîê asci òàáëèöû îò 0 äî 8 âêë

		if (choose == "1")
		{

		}
		else if (choose == "2")
		{
			ShowStorage();
		}
		else if (choose == "3")
		{

		}
		else if (choose == "4")
		{

		}
		else if (choose == "5")
		{

		}
		else if (choose == "6")
		{

		}
		else if (choose == "7")
		{

		}
		else if (choose == "8")
		{

		}
		else if (choose == "0")
		{
			break;
		}
		else
		{
			std::cerr << "MainMenuErorr";
		}
	}
}
void CreateStaticStorage()
{
	const int staticSize = 10;
	int idStaticArr[staticSize]{ 1,2,3,4,5,6,7,8,9,10 };
	std::string nameStaticArr[staticSize]
	{
		"Резиновые сапоги         ", "Варежки                     ", "Перчатки                     ", 
		"Термос                        ", "Теплые носки                  ", "Зимние ботинки             ",
		"Шапка                      ", "Термобелье                 ", "Штаны                      ", "Свитер                      "
	};
	int countStaticArr[staticSize]{10, 17 , 8 , 11 ,23, 27, 12,14,5,3};
	double priceStaticArr[staticSize] { 2390.90, 790.90, 649.90, 1190.90, 459.90, 6290.90, 1490.90, 1799.90, 3390.90, 2900.90 };

	SetArr(idStaticArr, idArr, staticSize);
	SetArr(nameStaticArr, nameArr, staticSize);
	SetArr(countStaticArr, countArr, staticSize);
	SetArr(priceStaticArr, priceArr, staticSize);

}

void ShowStorage()
{
	std::cout << "ID\tНазвание\t\t\tЦена\tКоличество\n\n";
	for (int i = 0; i < size; i++)
	{
		std::cout << idArr[i] << "\t" << nameArr[i] << "\t"
			<< priceArr[i] << "\t" << countArr[i] << "\n";
	}
}

template<typename ArrType>
void SetArr(ArrType staticArr, ArrType dynamicArr, int size)
{
	for (int i = 0; i < size; i++)
	{
		dynamicArr[i] = staticArr[i];
	}


};

template<typename ArrType>
void PrintArr(ArrType dynamicArr, int size)
{
	for (int i = 0; i < size; i++)
	{
		std::cout << dynamicArr[i] << " ";
	}
	std::cout << "\n";


}
