#include <bits/stdc++.h>
#define rep(i,n) for(int i=0, i##_len=(n); i<i##_len; ++i)
using namespace std;
using ll = long long;
using d = double;

int main(){
  int n;
  string s;
  cin >> n >> s;
  vector<int> m(n);
  rep(i,n){
    if(s[i]=='R')m[i]=0;
    if(s[i]=='B')m[i]=1;
    if(s[i]=='G')m[i]=2;
  }
  vector<ll> c(3);
  rep(i,n)c[m[i]]++;
  ll t=c[0]*c[1]*c[2];
  rep(j,n){
    rep(i,j){
      int k=j+(j-i);
      if(k<n){
      	if(m[i]==m[j])continue;
        if(m[j]==m[k])continue;
        if(m[k]==m[i])continue;
      	--t;
      }
    }
  }
  cout << t << endl;
  return 0;
}