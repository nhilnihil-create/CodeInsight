#include<iostream>
#include<string>
using namespace std;

int main()
{
	//string cat;
	//cin >> cat;
	//for (int i = 0; i < 3; i++)
	//{
	//	if (cat[i] == '7')
	//	{
	//		cout << "Yes";
	//		exit(0);
	//	}
	//}
	//cout << "No";
	
	long long num;
	long long duck = 0;
	cin >> num;
	for (int i = 1; i <= num; i++)
	{
		if (i % 3 == 0)continue;
		else if (i % 5 == 0)continue;
		duck += i;
	}
	cout << duck;
	return 0;
}

