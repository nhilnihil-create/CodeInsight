#include <bits/stdc++.h>
#define rep(i,n) for(int i=0, i##_len=(n); i<i##_len; ++i)
using namespace std;
using ll = long long;
using d = double;
 
int main(){
  int n;
  string s;
  cin >> n >> s;
  vector<int> m(3);
 
  rep(i,n){
    if(s[i]=='R')++m[0];
    if(s[i]=='B')++m[1];
    if(s[i]=='G')++m[2];
  }
  ll t=1;
  rep(i,3) t*=m[i];
  for(int j=1;j<n;++j){
    rep(i,j){
      int k=j+(j-i);
      if(k>=n)continue;
      if(s[i]==s[j] || s[j]==s[k] || s[k]==s[i])continue;
      --t;
    }
  }
  cout << t << endl;
  return 0;
}