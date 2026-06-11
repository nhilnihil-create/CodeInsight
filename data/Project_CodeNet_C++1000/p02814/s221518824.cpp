#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int MAX_N = 1e5+2, MAX_M = 1e6+1;
ll N, M;
ll a[MAX_N];

ll lcm(ll a, ll b)
{
    return a/__gcd(a,b) * b;
}

void solve()
{
	// X = A *(2*P+1)
	for(int i=0;i<N;++i) a[i] >>= 1;
	ll L = 1;
	for(int i=0;i<N;++i){
        L = lcm(L, a[i]);
        if(L > M || L < 0){
            cout << 0 << '\n';
            return;
        }
	}
	//cout << L << '\n';
	for(int i=0;i<N;++i){
	    ll x = L / a[i];
	    if(x%2 == 0){
	        cout << 0 << '\n';
	        return;
	    }
	}
	ll res = M / L;
	if(res % 2 == 0) res--;
	cout << (res+1)/2 << '\n';
}

int main()
{
	cin >> N >> M;
	for(int i=0;i<N;++i) cin >> a[i];
	solve();
	return 0;
}