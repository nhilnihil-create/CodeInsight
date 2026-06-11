#include <iostream>
#include <cstring>
#include<vector>
#include <algorithm>
#include<cstdlib>
#include<set>
#include<math.h>
#include<map>
using namespace std;
using ll = long long;
using ull = unsigned long long;
#define rep(i,n) for(ll i=0;i<n;i++)

bool f(int x)
{
	int a = 0;
	for (int i = 2; i * i <= x; i++)
	{
		if (x % i == 0)
		{
			a = 1;
			break;
		}
	}
	if (a == 1) return false;
	else return true;
}

int main()
{
	ll x;
	cin >> x;

	int y = 0;
	while (y == 0)
	{
		if (f(x))
		{
			y = x;
		}
		x++;
	}
	
	cout << y << "\n";
	return 0;
}