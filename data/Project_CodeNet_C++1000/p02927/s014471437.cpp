#include<bits/stdc++.h>
using namespace std;
int main(){
  cin.tie(0);
  ios::sync_with_stdio(false);
  int m, d;
  cin >> m >> d;
  int ans = 0;
  for(int i = 4; i <= m; i++){
    for(int j = 22; j <= d; j++){
      if(i == (j%10)*(j/10) && (j%10) >= 2 && (j/10) >= 2) ans++;
    }
  }
  cout << ans << endl;
  return 0;
}