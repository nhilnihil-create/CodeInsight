#include<bits/stdc++.h>
using namespace std;
int main(){
  int n,k;
  cin >> n >> k;
  double a[n],ans,s[n],ke;
  s[0]=0.0;
  for(int i=1;i<=n;i++){
    cin >> a[i];
    double an=1+a[i];
    s[i]=an+s[i-1];
  }
  for(int i=0;i<=n-k;i++){
    ke=s[i+k]-s[i];
    ans=max(ke,ans);
  }
  printf("%.10f",ans/2);
}