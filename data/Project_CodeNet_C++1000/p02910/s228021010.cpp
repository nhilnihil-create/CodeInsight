#include <iostream>
#include <string>

using namespace std;

int main()
{
	char flag = 1;
	string S;
	cin >> S;
	for (int count = 0; count < S.length(); count++)
	{
		if (count % 2 == 0)
		{
			if (S.at(count) == 'L')
			{
				flag = 0;
			}
		}
		else
		{
			if (S.at(count) == 'R')
			{
				flag = 0;
			}
		}
	}
	if (flag)
	{
		cout << "Yes" << endl;
	}
	else
	{
		cout << "No" << endl;
	}
}