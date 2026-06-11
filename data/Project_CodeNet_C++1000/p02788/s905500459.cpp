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


int main() {
  int N; cin >> N;
  ll D,A,x,h;
  cin >> D >> A; // 範囲　爆弾
  vector<vector<ll>> XH(N);
  rep(i,N) {
    cin >> x >> h;
    XH[i] = {x,h}; // 場所　体力
  }
  sort(XH.begin(),XH.end());
  ll cnt=0;
  queue<vector<ll>> bomb;
  ll now=0;
  rep(i,N) {
    auto t = XH[i];
    while (!bomb.empty() && bomb.front()[0]<t[0]-D){
      now-=bomb.front()[1]; bomb.pop();
    }
    t[1]-=now*A;
    if (t[1]<0) continue;
    ll add = (t[1]+A-1)/A;
    cnt+=add;
    now+=add;
    bomb.push({t[0]+D ,add});
  }
  cout << cnt << endl;
}