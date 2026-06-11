#include <bits/stdc++.h>
using namespace std;
using ll = long long;

ll N, K;

void solve()
{
	if(N == 0) cout << 0 << '\n';
	else{
		if(K==1) cout << 0 << '\n';
		else{
			ll x=N/K;
			cout << min(abs(N-x*K), abs(N-(x+1)*K)) << '\n';
		}
	}
}

int main()
{
	cin >> N >> K;
	solve();
	return 0;
}