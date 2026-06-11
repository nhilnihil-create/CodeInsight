#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ii pair<int, int>
#define dd pair<double, double>
#define pb(i) push_back(i)
const double PI = 3.14159265359;
const int inf = 1e9+77;
const ll mod = 1e9+7;
const double eps = 1e-7;
//int dir1[8] = {0, 0, 1, -1, 1, -1, 1, -1};
//int dir2[8] = {1, -1, 0, 0, 1, 1, -1, -1};
int dir1[4] = {0, 0, 1, -1};
int dir2[4] = {1, -1, 0, 0};

int main()
{
	int i, j, k;

	ll ans = 0;
	int n; cin >> n;
	for(i = 1; i <= n; i++)
		for(j = 1; j <= n; j++)
			for(k = 1; k <= n; k++)
				ans += __gcd(i, __gcd(j, k));
	cout << ans << '\n';

}
