#include<stdio.h>
#include<math.h>
#include<iostream>
#include<string>
#include<vector>
using namespace std;
int main()
{
	string s;
	int n,count=0;
	cin >> n >> s;
	for (int i = 0; i < n-1; i++)
	{
		if (s[i] == s[i + 1])
		{
			count++;
		}
	}
	cout << n-count << endl;
}