#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
   	
int main() {
	int flag = 0;
	string s;
	cin >> s;

	for (int i = 0; i < 3; i++)
	{
		if (s[i] == s[i+1])
		{
			flag = 1;
		}
	}

	if (flag == 1)
	{
		cout << "Bad";
	}
	else
	{
		cout << "Good";
	}

	return 0;
}

