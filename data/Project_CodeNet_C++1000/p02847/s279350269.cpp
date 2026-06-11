#include<iostream>
#include<cmath>
#include<vector>
#include<algorithm>
#include<stack>
using namespace std;

int main()
{
	string s[7] = { "SUN","MON","TUE","WED","THU","FRI","SAT" };

	string in;
	cin >> in;

	for (int i = 0; i < 7; i++)
	{
		if (in == s[i])
		{
			cout << 7 - i;
			break;
		}
	}
	
}
