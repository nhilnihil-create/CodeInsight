#include <bits/stdc++.h>
#define rep(i,n) for(int i=0;i<(int)(n);i++)
using namespace std;

using ll = long long;

const int INF = 1001001001;
const ll INF_LL = 1001001001001001001LL;

int main(void){
  int n; cin >> n;
  vector<int> a(n+1),b(n+1),c(n-1+1);
  for(int i = 1;i<=n;i++) cin >> a[i];
  for(int i = 1;i<=n;i++) cin >> b[i];
  for(int i = 1;i<=n-1;i++) cin >> c[i];

  int ans = 0;
  for(int i = 1;i<=n;i++){
    if(i>1 && a[i]-a[i-1]==1) ans += b[a[i]]+c[a[i]-1];
    else ans += b[a[i]];
  }

  cout << ans << endl;
  
  return 0;
}
