#include <bits/stdc++.h>
#define rep(i,n) for(int i=0;i<(int)(n);i++)
using namespace std;

using ll = long long;

const int INF = 1001001001;
const ll INF_LL = 1001001001001001001LL;

int main(void){
  int n; cin >> n;
  vector<int> b(n); for(int i = 1;i<=n-1;i++) cin >> b[i];

  int ans = b[1];
  for(int i = 1;i<n-1;i++){
    ans += min(b[i],b[i+1]);
  }
  ans += b[n-1];
  /*ans = b[0]*2;
    for(int i = 1;i<n-1;++i) ans += b[i];*/

  cout << ans << endl;
  
  return 0;
}
