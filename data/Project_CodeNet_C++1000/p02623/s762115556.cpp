#include <bits/stdc++.h>
using namespace std;
int a[200010],b[200010];
long long sa[200010],sb[200010];
int n,m,k,ans = 0;
int Binary_search(int sum){
    int l = 0,r = m,mid;
    while(l < r){
       mid = (l+r+1)/2;//+1取决于mid-1
       if(sb[mid]+sum>k){
        r = mid - 1;
       }else{
        l = mid;
       }
    }
    return l;
}
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
  for(int i = 0; i <= n; i++){
    if(sa[i] <= k){
        ans = max(ans,i+Binary_search(sa[i]));
    }
  }
  cout << ans << endl;
  return 0;
}
