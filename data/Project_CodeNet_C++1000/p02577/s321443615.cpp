// Author : Mohamed sameh
#include <bits/stdc++.h>
typedef long long ll ;
#define pb push_back
#define f first
#define s second
#define all(v) v.begin(),v.end()
#define rall(v) v.rbegin(),v.rend()
#define SZ(a) (int)a.size()
#define Flush fflush(stdout);
using namespace std ;
int main()
{
	string x;
	cin >> x;
	int sum = 0;
	for (int i = 0; i < SZ(x); i++)
	{
		sum += x[i] - '0';
	}
	cout << (sum % 9? "No\n" : "Yes\n");
}
