#include<stdio.h>
#include<math.h>
#include<iostream>
#include<string>
#include<vector>
using namespace std;
int main()
{
	string S;
	cin >> S;
	string T;
	cin >> T;
	int a;
	a = 0;
	int b;
	b = 0;
	while(a<3)
	{
		if (S[a] == T[a])
		{
			b++;
		}

		a++;
	}
	cout << b << endl;
}