#include <iostream>
#include <cstring>
#include<vector>
#include <algorithm>
#include<cstdlib>
#include<set>
#include<math.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
#define rep(i,n) for(ll i=0;i<n;i++)

int main()
{
	int a, b;
	cin >> a >> b;
	if (a <= b)
	{
		rep(i, b)
		{
			cout << a;
		}
		cout << "\n";
	}
	else
	{
		rep(i, a)
		{
			cout << b;
		}
		cout << "\n";
	}

	return 0;
}