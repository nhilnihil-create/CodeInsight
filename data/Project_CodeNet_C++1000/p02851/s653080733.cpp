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
  vector<ll> A(N),sep(N+1,0);
  rep(i,N) {
    cin >> A[i];
    if (i>0) A[i]+=A[i-1];
    A[i]%=K;
    sep[i+1] = A[i]-(i+1);
    sep[i+1]%=K;
    if (sep[i+1]<0) sep[i+1]+=K;
  }

  ll res=0;
  map<ll,int> mp;
  mp[0]++;
  rep2(i,1,N+1) {
    if (i-K>=0) mp[sep[i-K]]--;
    mp[sep[i]]++;
    res+=mp[sep[i]]-1;
  }
  cout << res << endl;
}