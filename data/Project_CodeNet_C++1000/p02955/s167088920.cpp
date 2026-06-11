#include <bits/stdc++.h>
using namespace std;

template<class T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return 1; } return 0; }

using ll = long long;

const int dx[4] = {1, 0, -1, 0};
const int dy[4] = {0, 1, 0, -1};
const int INF = 1<<30;
const ll mod = 1000000007LL;

ll pow(ll a, ll n) {
	ll ret = 1LL;
	for (; n > 0LL; n >>= 1LL, a = a * a) {
		if (n % 2LL == 1LL) {
			ret = ret * a;
		}
	}
	return ret;
}

int main() {
  ll N,K;
  cin>>N>>K;
  vector<ll> v(N);
  for(ll i = 0; i < N; i++) cin>>v[i];
  ll total = 0;
  for(auto x:v) total+=x;
  map<ll,ll> m;
  ll s = total;
  for(ll i = 2; i*i<=total; i++){
    while(s%i==0){
      s/=i;
      m[i]++;
    }
  }
  if(s!=1) m[s]++;
  vector<ll> ya;
  ya.push_back(1LL);
  for(auto x:m){
    ll s = ya.size();
    for(ll i = 0; i < s; i++){
      for(ll j = 1; j <= x.second;j++){
        ya.push_back(ya[i]*pow(x.first,j));
      }
    }
  }
  sort(ya.begin(),ya.end());
  reverse(ya.begin(),ya.end());
  for(ll i = 0; i < (ll)ya.size(); i++){
    vector<ll> w(N);
    for(ll j = 0; j < N; j++) w[j]=v[j]%ya[i];
    sort(w.begin(),w.end());
    reverse(w.begin(),w.end());
    ll T = 0LL;
    for(auto x:w) T+=x;
    T/=ya[i];
    ll cnt = 0;
    for(ll j = 0; j < T; j++){
      cnt+=ya[i]-w[j];
    }
    if(cnt<=K){
      cout<<ya[i]<<endl;
      break;
    }
  }
}