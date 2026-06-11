#include<bits/stdc++.h>
using namespace std;
int main(){
  int m,d,ans = 0,i,j,a,b;cin >> m >> d;
  for(i=4;i<=m;i++){
    for(j=22;j<=d;j++){
      a = j/10;b = j%10;
      if(a < 2 || b < 2) continue;
      if(i==a*b) ans++;
    }
  }
  cout << ans << "\n";
}
