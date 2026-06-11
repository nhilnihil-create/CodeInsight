#include <iostream>
#include <algorithm>
using namespace std;
typedef long long ll;


int main(void){
  ll n,k,i,j,a[2003],me[2003]={},mv[2003]={},ans=0;
  const int mod=1e9+7;
  
  cin >> n >> k;
  for (i=0;i<n;i++) cin >> a[i];
  
  for (i=0;i<n-1;i++) for (j=i+1;j<n;j++){
    if (a[i]>a[j]) me[i]++;
  }
  
  for (i=0;i<n;i++) for (j=0;j<n;j++){
    if (i==j) continue;
    if (a[i]>a[j]) mv[i]++;
  }
  
  for (i=0;i<n;i++){
    ans=(ans+k*(k-1)/2%mod*mv[i]%mod+me[i]*k%mod)%mod;
  }
  
  cout << ans << endl;
  
  return 0;
}