#include<bits/stdc++.h>
using namespace std;
#define fio ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

const ll MOD = 1e9 + 7;
const ll INF = 1e9 + 9;
const ll N   = 500500;

int main()
{
	fio
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	ll n , i, j, k;
	cin >> n;
	ll ans =  0;
	for (i = 1; i <= n - 1; i++)
	{
		ans+= (n-1)/i;
	}
	cout << ans << "\n";
	return 0;

}