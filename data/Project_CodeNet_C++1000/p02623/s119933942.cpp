#include <bits/stdc++.h>
using namespace std;
int a[200010],b[200010];
long long sa[200010],sb[200010];
int n,m,k,ans = 0;
int main() {
  cin >> n >> m >> k;
  sa[0] = sb[0] = 0;
  for(int i = 1; i <= n; i++){
        cin >> a[i];
        sa[i] = sa[i-1]+a[i];
  }
  for(int i = 1; i <= m; i++){
        cin >> b[i];
        sb[i] = sb[i-1]+b[i];
  }
  for(int i = 0,j = m; i <= n; i++){
    if(sa[i] <= k){
        while(sa[i] + sb[j] > k){
            j--;
        }
        ans = max(ans,i+j);
    }else
        break;
    
  }
  cout << ans << endl;
  return 0;
}
