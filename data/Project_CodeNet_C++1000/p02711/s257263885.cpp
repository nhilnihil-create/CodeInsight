#include<iostream>
#include<vector>
#include<algorithm>
#include<cmath>
#include<string>

using namespace std;

int main()
{
	string s;
	cin >> s;
	
	for (int i = 0; i < 3; i++)
	{
		if (s[i] == '7')
		{
			cout << "Yes";
			return 0;
		}
	}

	cout << "No";
	return 0;

}