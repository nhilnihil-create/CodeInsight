#include <bits/stdc++.h>
#define rep(i,n) for(int i=0;i<(n);++i)
using namespace std;
using ll = long long;

int main() {
  int L,R,d,ans=0;
  cin >> L >> R >> d;
  for(int i=L;i<R+1;i++){
    if(i%d==0)ans++;
  }
  
  cout << ans << endl;

  return 0;
}