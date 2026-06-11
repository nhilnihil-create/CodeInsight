#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i,n) for(int i=0;i<n;i++)
#define rep2(i,a,b) for(int i=(a);i<(b);++i)

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
  ll K,res=0,cnt=1;
  string S;
  cin >> S >> K;
  vector<ll> ans;

  if (S[0]==S[S.size()-1]) cnt++;
  rep2(i,1,S.size()){
    if (S[i]!=S[i-1]) {
      if (cnt>1) ans.push_back(cnt);
      cnt=0;
    };
    cnt++;
  }
  if (cnt==S.size()+1) {
    res += (cnt-1)*K/2;
    cout <<res << endl;
    return 0;
  }
  else if (S[0]==S[S.size()-1]) {
    res+=(ans[0]-1)/2;
    res+=cnt/2;
    ll tmp = ans[0]+cnt-1;
    res+=tmp/2*(K-1);
    rep2(i,1,ans.size()) res+=ans[i]/2*K;
    cout <<res << endl;
    return 0;
  }
  else if (cnt>1) ans.push_back(cnt);
  for (auto i:ans) res+=i/2*K;
  cout << res << endl;
}