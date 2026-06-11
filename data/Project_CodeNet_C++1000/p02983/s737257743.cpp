#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i = 0;i < n;i++)
using ll = long long;

int main(){
  ll l,r,rl,i,j,ans=2019;
  cin >>l >>r;
  rl = r-l;
  if(rl>2018) ans = 0;
  else{
    for(i = 0; i<=rl; i++){
      for(j = i+1; j<=rl; j++) ans = min(ans, (l+i)*(l+j)%2019);
    }
  }
  cout << ans << endl;
  return 0;
}