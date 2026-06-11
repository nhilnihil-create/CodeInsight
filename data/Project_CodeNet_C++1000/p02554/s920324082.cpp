#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;

int main() {
	ll N;
	cin >> N;
  
    const ll MOD = 1000000007;
    ll ans1=1;
  	for(ll i=1; i<=N; ++i) {
        ans1 *= 10;
        ans1 %= MOD;
    }
    ll ans2=1;
    for(ll i=1; i<=N; ++i) {
        ans2 *= 9;
        ans2 %= MOD;
    }
    ll ans3=1;
    for(ll i=1; i<=N; ++i) {
        ans3 *= 8;
        ans3 %= MOD;
    }

    ll ans = ans1-ans2-ans2+ans3;
    ans %= MOD;
    ans = (ans+MOD)%MOD;

    cout << ans << endl;
  
    return 0;
}
