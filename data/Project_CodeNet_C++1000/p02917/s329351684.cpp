#include<bits/stdc++.h>
using namespace std;
int a[105],b[105],n;
int main(){
  cin>>n;
  for(int i=1;i<n;i++)cin>>b[i];
  a[1]=b[1];b[n]=b[n-1];
  for(int i=2;i<=n;i++)a[i]=min(b[i],b[i-1]);
  int ans=0;
  for(int i=1;i<=n;i++)ans+=a[i];
  cout<<ans;
  return 0;
}