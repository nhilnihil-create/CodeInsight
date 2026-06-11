#include <bits/stdc++.h>
#define rep(i,n) for(int i=0;i<(n);++i)
using namespace std;
using ll = long long;

int main() {
  int X,ans=1,x=1800;
  cin >> X;
  
  while(x>X){
    x = x-200;
    ans++;
  }
  cout << ans << endl;
  
  return 0;
}