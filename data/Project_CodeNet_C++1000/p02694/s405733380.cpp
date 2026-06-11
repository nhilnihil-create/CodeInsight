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
	ull x;
	cin >> x;
	ull ans = 0;
	ull n = 100;
	while (n<x)
	{
		ans++;
		n +=n/100;
	}

	cout << ans << "\n";

	return 0;
}