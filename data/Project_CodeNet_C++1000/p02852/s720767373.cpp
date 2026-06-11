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
  int N,M;
  cin >> N >> M;
  string S; cin >> S;
  vector<int> g(1,1);
  // rep2(i,1,N+1) {
  //   if (S[i]==S[i-1]) g[g.size()-1]++;
  //   else g.push_back(1);
  // }
  // reverse(g.begin(),g.end());
  reverse(S.begin(),S.end());
  vector<int> ans;
  
  rep(i,N) {
    for (int j=M;j>0;j--) {
      if (i+j>N) continue;
      if (S[i+j]=='0') {
        ans.push_back(j);
        i = i+j-1;
        break;
      }
      if (j==1){
        cout << -1 << endl;
        return 0; 
      }
    }
  }
  reverse(ans.begin(),ans.end());
  for (auto p:ans) cout << p << ' ';
  cout << endl;
}