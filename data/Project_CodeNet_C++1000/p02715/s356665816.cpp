#include <bits/stdc++.h>
using namespace std;

template<class T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return 1; } return 0; }

using ll = long long;
using P = pair<int,int>;
using graph = vector<vector<int>>;

const int dx[4] = {1, 0, -1, 0};
const int dy[4] = {0, 1, 0, -1};
const ll INF = 1LL<<60;
const ll mod = 1000000007LL;

#define rep(i, n) for (int i = 0; i < (int)(n); i++)

ll pow(ll a, ll n, ll m) {
	ll ret = 1LL;
	for (; n > 0LL; n >>= 1LL, a = a * a % m) {
		if (n % 2LL == 1LL) {
			ret = ret * a % m;
		}
	}
	return ret;
}

int main() {
    ll N,K;
    cin>>N>>K;
    vector<ll> cnt(K+1,0);
    for(ll i = K; i>0; i--){
        ll c = K/i;
        cnt[i] = pow(c,N,mod);
        for(ll j = 2; i*j<=K; j++){
            cnt[i] = (cnt[i] - cnt[j*i])%mod;
        }
    }
    ll ans = 0;
    rep(i,K+1){
        ans = (ans + i*cnt[i])%mod;
    }
    if(ans<0) ans += mod;
    cout<<ans<<endl;
}