#include<bits/stdc++.h>
using namespace std;
#define int long long int
int32_t main(){
    int i,n,k,ans=1000;
    cin>>n;
    int a[n+5]={0};
    for(i=1;i<=n;i++){
        cin>>a[i];
    }
   for(i=1;i<=n;i++){
      if(a[i+1]>a[i]){
          k=(ans)/a[i];
          ans=ans%a[i]+(k*a[i+1]);
      }
   }cout<<ans<<"\n";
    return 0;
}