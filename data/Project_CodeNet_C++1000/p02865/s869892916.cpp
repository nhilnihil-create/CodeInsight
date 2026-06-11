#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int N;

void solve()
{
	int ans = N/2;
	if(N%2 == 0) ans--;
	cout << ans << '\n';
}

int main()
{
	cin >> N;
	solve();
	return 0;
}