#include <bits/stdc++.h>
using namespace std;
int main(){
  int n,b,c;
  cin>>n;
  int a[n+1];
  long long ans=0;
  for(int i=0;i<n+1;i++)cin>>a[i];
  for(int i=0;i<n;i++){
    cin>>b;
    c=a[i+1]+a[i];
    ans+=min(c,b);
    a[i+1]=clamp(c-b,0,a[i+1]);
  }
  cout<<ans<<endl;
}