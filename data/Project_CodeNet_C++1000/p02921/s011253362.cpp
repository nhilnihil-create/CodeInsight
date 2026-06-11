#include<iostream>
#include<cmath>
#include<vector>
#include<algorithm>
#include<stack>
using namespace std;

int main()
{
	string s, c;
	cin >> s;
	cin >> c;

	int j = 0;
	for (int i = 0; i < 3; i++)
	{
		if (s[i] == c[i])
		{
			j++;
		}
	}
	cout << j;
}
