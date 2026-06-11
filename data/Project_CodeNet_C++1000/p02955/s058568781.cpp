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
  ll N,K;
  cin >> N >> K;
  vector<ll> A(N);
  ll s=0;
  rep(i,N) {
    cin >> A[i];
    s+=A[i];
  }
  auto div = divisor(s);
  ll ans=1,cnt;
  
  for (auto t:div) {
    vector<ll> inc(N),dic(N),tA(N);
    rep(i,N) tA[i]=A[i]%t;
    sort(tA.begin(),tA.end());
    rep(i,N) {
      dic[i]=tA[i];
      if (i>0) dic[i]+=dic[i-1];
    }
    rep(i,N) {
      inc[i]=t-tA[N-1-i];
      if (i>0) inc[i]+=inc[i-1];
    }
    reverse(inc.begin(),inc.end());
    rep(i,N-1){
      if (dic[i]==inc[i+1]&&dic[i]<=K) {chmax(ans,t);break;}
    }
    // cout << t << endl << dic << endl << inc << endl;
  }
  cout << ans << endl;
}