#include <bits/stdc++.h>
using namespace std ;
#define ll long long

inline int D(){
    int t ;
    scanf( "%d" , &t ) ;
    return t ;
}
inline ll LLD(){
    ll t ;
    scanf( "%lld" , &t ) ;
    return t ;
}
//const int INF = 0x3f3f3f3f;
//const int mod=1e9+7;
//const double pi=3.14159265359;
//###################################################################

int main() {
  int n=D(),m=D(),k=D();
  int a[n],b[m];
  ll cm1[n+1],cm2[m+1];
  cm1[0]=0,cm2[0]=0;
  for(int i=0;i<=n;i++){
      if(i<n)
      a[i]=D();
      if(i)
        cm1[i]=cm1[i-1]+a[i-1];
  }

  for(int i=0;i<=m;i++){
      if(i<m)
      b[i]=D();
      if(i)
          cm2[i]=cm2[i-1]+b[i-1];
  }
  int ans=0;
  for(int i=0;i<=n&&cm1[i]<=k;i++){
        if(cm1[i]>k)break;
        int it=upper_bound(cm2,cm2+m+1,(k-cm1[i]))-cm2;
        ans=max(ans,i+it-1);
  }
  cout<<ans;


}