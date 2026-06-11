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
  string S;
  cin>>S;
  ll N = S.size();
  vector<int> v(N);
  int c = 1;
  reverse(S.begin(),S.end());
  rep(i,N){
    int t = S[i] - '0';
    if(i==0) v[i] = t;
    else v[i] = (v[i-1] + t*c)%2019;
    c = (c*10)%2019;
  }
  map<int,ll> m;
  rep(i,N) m[v[i]]++;
  m[0]++;
  ll ans = 0;
  for(auto x:m){
    ans += x.second*(x.second-1)/2;
  }
  cout<<ans<<endl;
}