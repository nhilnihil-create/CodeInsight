#include <bits/stdc++.h>
using namespace std;

template<class T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return 1; } return 0; }

using ll = long long;

const int dx[4] = {1, 0, -1, 0};
const int dy[4] = {0, 1, 0, -1};
const ll mod = 1000000007LL;

ll pow(ll a, ll n, ll m) {
	ll ret = 1LL;
	for (; n > 0LL; n >>= 1LL, a = a * a % m) {
		if (n % 2LL == 1LL) {
			ret = ret * a % m;
		}
	}
	return ret;
}

ll combination(ll x, ll y){
  if(y>x) return 0LL;
  ll c = 1LL;
  for(ll i = 0LL; i < y; i++){
    c *= (x-i)%mod;
    c %= mod;
    c*= pow(i+1,mod-2,mod);
    c%=mod;
  }
  return c;
}

int main() {
  ll N, K;
  cin >> N >> K;
  for(ll i = 1LL; i <= K; i++) {
    cout<<((combination(K-1,i-1)*combination(N-K+1,i))%mod) << endl;
  }
}
