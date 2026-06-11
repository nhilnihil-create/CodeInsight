#include <iostream>
#include <string>

using namespace std;

int main()
{
	int		Cnt;
	int		Taro = 0;
	int		Hana = 0;

	auto ToLower = [](string &str)
	{
		for (auto &it : str)
			it = tolower(it);
	};

	cin >> Cnt;

	string	strTaro;
	string	strHana;

	for (int i = 0; i < Cnt; i++)
	{
		cin >> strTaro >> strHana;
		ToLower(strTaro);
		ToLower(strHana);

		if (strTaro > strHana)
		{
			Taro += 3;
		}
		else if (strTaro < strHana)
		{
			Hana += 3;
		}
		else
		{
			Taro += 1;
			Hana += 1;
		}
	}

	cout << Taro << " " << Hana << "\n";

	return 0;
}