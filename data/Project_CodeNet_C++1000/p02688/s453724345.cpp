#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <cmath>
#include <vector>
#include <set>
#include <map>
#include <unordered_set>
#include <unordered_map>
#include <queue>
#include <ctime>
#include <cassert>
#include <complex>
#include <string>
#include <cstring>
#include <chrono>
#include <random>
#include <bitset>
using namespace std;

#define pb push_back
#define s(a) (int)(a).size()
#define all(x) (x).begin(),(x).end()
#define endl ("\n")

using ll = long long;
using ld = long double;
const ll M = 1000000007;
const ld pi = 3.14159265358979323846;

long long mod(long long x)
{
    return ((x%M + M)%M);
}

long long add(long long a, long long b)
{
    return mod(mod(a)+mod(b));
}

long long mul(long long a, long long b)
{
    return mod(mod(a)*mod(b));
}

void solve()
{
	int n, k;
	cin >> n >> k;
	map <int, int> mp;
	for(int i = 0; i < k; i++)
	{
		int t;
		int a;
		cin >> t;
		while(t--)
		{
			cin >> a;
			mp[a]++;
		}
	}
	ll sum = 0;
	for(int i = 1; i <= n; i++)
	{
		if(mp[i] == 0)
			sum++;
	}
	cout << sum << endl;
}

int main()
{
	/*ios::sync_with_stdio(0);
	cin.tie(0);*/

	int tt = 1;
	//cin >> tt;
	for(int test_case = 1; test_case <= tt; test_case++)
	{
		//cout << "Case #" << test_case << ": ";
		solve();
	}
	return 0;
}
