#include<bits/stdc++.h>
using namespace std;
int main(){
  int64_t A,B,n,m,k,j,ans=0;
  cin >> n >> m >> k;
  int64_t a[n+1],b[m+1];
  a[0]=0,b[0]=0;
  for(int64_t i=1;i<=n;i++){
    cin >> a[i];
    a[i]+=a[i-1];
  }
  for(int64_t i=1;i<=m;i++){
    cin >> b[i];
    b[i]+=b[i-1];
  }
  j=m;
  for(int i=0;i<=n;i++){
    if(k<a[i])break;
    while(b[j]>k-a[i])j--;
    ans=max(ans,i+j);
  }
  cout << ans << endl;
}
    
    