#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using ll = long long;

int main() {
  int n;
  string s;
  cin >> n >> s;
  ll ans=0;
  rep(i,10)rep(j,10)rep(k,10){
    int x=0;
    rep(l,n){
      if(x==2){
        if(s[l]=='0'+k)x++;
      }
      if(x==1){
        if(s[l]=='0'+j)x++;
      }
      if(x==0){
        if(s[l]=='0'+i)x++;
      }
      if(x==3){
        ans++;
        x++;
      }
    }
  }
  cout << ans << endl;
      
      
}