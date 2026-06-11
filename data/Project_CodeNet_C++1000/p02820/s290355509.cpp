#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i = 0;i < n;i++)
using ll = long long;

int main(){
  int n,k,r,s,p;
  string t; cin >>n >>k >>r >>s >>p >>t;
  rep(i,n-k) {
    if(t[i]==t[i+k]) t[i+k]='*';
  }
  int ans = 0;
  rep(i,n){
    if(t[i]=='r') ans += p;
    if(t[i]=='s') ans += r;
    if(t[i]=='p') ans += s;
  }
  cout << ans << endl;
  return 0;
}