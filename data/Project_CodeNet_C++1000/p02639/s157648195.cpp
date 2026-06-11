#include <bits/stdc++.h>
#define rep(i,n) for(int i=0; i<(n); i++)
using namespace std;

int main(){
  int ans=15, x[5];
  rep(i,5) cin >> x[i];
  rep(i,5)ans-=x[i];
  cout << ans << endl;
  return 0;
}