#include <bits/stdc++.h>
using namespace std;
using ll = long long;

ll A;

void solve()
{
	const int n = 1e9;
	ll y = A/n, q = A%n;
	while(q > 0){
		y++, q-=n;
	}
	cout<<0<<' '<<0 << ' ' << n << ' ' << 1 << ' '<< -q <<' ' << y<<'\n';
}

int main()
{
	cin >> A;
	solve();
	return 0;
}