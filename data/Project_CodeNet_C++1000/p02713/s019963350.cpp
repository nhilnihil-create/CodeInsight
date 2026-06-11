#include<iostream>
#include<string>
using namespace std;

int gcd(int x, int y);

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
	
	//long long num;
	//long long duck = 0;
	//cin >> num;
	//for (int i = 1; i <= num; i++)
	//{
	//	if (i % 3 == 0)continue;
	//	else if (i % 5 == 0)continue;
	//	duck += i;
	//}
	//cout << duck;

	int ans = 0;
	int dog;
	cin >> dog;
	for (int i = 1; i <= dog; i++)
	{
		for (int j = 1; j <= dog; j++) 
		{
			for (int k = 1; k <= dog; k++)
			{
				ans += gcd(i, gcd(j, k));
			}
		}
	}
	cout << ans;


	return 0;
}

int gcd(int x, int y)
{
	if (x%y == 0)
		return y;
	else
		return gcd(y, x%y);
}
