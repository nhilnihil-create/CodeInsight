#include <bits/stdc++.h>
using namespace std;
int main(){
  int n,b;
  cin>>n;
  int a[n+1];
  long long ans=0;
  for(int i=0;i<n+1;i++)cin>>a[i];
  for(int i=0;i<n;i++){
    cin>>b;
    ans+=min(a[i],b);
    b=max(0,b-a[i]);
    ans+=min(a[i+1],b);
    a[i+1]=max(0,a[i+1]-b);
  }
  cout<<ans<<endl;
}