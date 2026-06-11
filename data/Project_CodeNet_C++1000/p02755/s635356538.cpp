#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
//using ll = long long;
//using P = pair<int,int>;

int main(){
  int a,b;
  cin >> a >> b;
  int ans =10000;
   rep(i,10000){
   if(i*8/100 == a && i*10/100 == b && i<ans) ans = i;
  }
  if(ans == 10000) cout << -1 << endl;
  else cout << ans << endl;
}