#include<bits/stdc++.h>
using namespace std;
int main(){
  long long n,k,ans = 0,i,j,b = 0;cin >> n >> k;
  long long a[n];
  for(i=0;i<n;i++) cin >> a[i];
  for(i=0;i<n-1;i++){
    for(j=i+1;j<n;j++){
      if(a[i]==a[j]) continue;
      if(a[i]>a[j]) ans = (ans+(k+1)*k/2)%1000000007;
      else ans = (ans+(k-1)*k/2)%1000000007;
    }
  }
  cout << ans << "\n";
}