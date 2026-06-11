#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;
const int mod = 1000000007;
const ll INF = 1001001001;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }

int main(){
  string s,t;
  cin >> s >> t;
  int n = int(s.size());
  int m = int(t.size());
  vector<vector<int>> dic(26);
  rep(i,n) dic[s[i]-'a'].push_back(i);
  rep(i,n) dic[s[i]-'a'].push_back(i+n);
  int p = 0;
  ll ans = 0;
  rep(i,m){
    int a = t[i] - 'a';
    if(dic[a].size()==0){
      puts("-1");
      return 0;
    }
    p = *lower_bound(dic[a].begin(),dic[a].end(),p) + 1;
    if(p>=n){
      ans += n;
      p -= n;
    }
  }
  ans += p;
  cout << ans << endl;
  return 0;
}