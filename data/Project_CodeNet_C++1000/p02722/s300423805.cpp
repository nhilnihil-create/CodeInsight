#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i,n) for(ll i=0;i<n;i++)
#define rep2(i,a,b) for(ll i=(a);i<(b);++i)

template<class T> inline void chmin(T& a, T b) {if (a > b) a = b;}
template<class T> inline void chmax(T& a, T b) {if (a < b) a = b;}

//vector出力
template <class T>ostream &operator<<(ostream &o,const vector<T>&v){
  o<<"{";
  for(int i=0;i<(int)v.size();i++) o << (i>0?", ":"") << v[i];
  o<<"}";
  return o;
}

//約数列挙
vector<ll> divisor(ll n) {
  vector<ll> ret;
  for(ll i = 1; i * i <= n; i++) {
    if(n % i == 0) {
      ret.push_back(i);
      if(i * i != n) ret.push_back(n / i);
    }
  }
  sort(begin(ret), end(ret));
  return (ret);
}


int main() {
  ll N;
  cin >> N;
  vector<ll> div = divisor(N-1);
  int ans = div.size();
  rep2(i,2,min(N,(ll)1000001)) {
    ll n = N;
    while(n%i==0) n/=i;
    if(n%i==1) {
      if (find(div.begin(),div.end(),i)==div.end()) {
        ans++;
      }
    }
  }
  cout << ans << endl;
}