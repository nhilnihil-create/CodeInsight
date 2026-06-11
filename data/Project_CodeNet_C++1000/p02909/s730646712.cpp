#include<iostream>
#include<cmath>
#include<vector>
#include<algorithm>
#include<stack>
using namespace std;

int main()
{
	string s[3] = { "Sunny", "Cloudy", "Rainy" };
	string ins;
	cin >> ins;
	int j;
	for (int i = 0; i < 3; i++)
	{
		if (s[i] == ins)
		{
			j = (i + 1) % 3;
			break;
		}
	}

	cout << s[j];
}
