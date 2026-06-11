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
    if(k>=a[i]){
      int64_t Left=0,Right=m+1;
      while(Right-Left>1){
        int64_t middle=(Left+Right)/2;
        if(b[middle]>k-a[i])Right=middle;
        else Left=middle;
      }
      ans=max(ans,i + Left);
    }
  }
  cout << ans << endl;
}