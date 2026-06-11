#include <bits/stdc++.h>
#define rep(i,n) for(int i=0;i<(n);++i)
using namespace std;
using ll = long long;

int main() {
  ll N,ans=0;
  cin >> N;
 
  for(int i=1;i<N+1;i++){
    if(i%3!=0 && i%5 != 0) ans = ans + i;
  }

  cout << ans << endl;
  
  return 0;
}