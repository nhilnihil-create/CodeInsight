#include <bits/stdc++.h>
using namespace std;
int main() {
  long long ans=0;
  int n; cin>>n;
  int a[n+1],b,c=0;
  for(int i=0;i<n+1;i++) cin>>a[i];
  for(int i=0;i<n;i++){
    cin>>b;
    ans+=min(c,a[i]);
    a[i]=max(a[i]-c,0);
    ans+=min(b,a[i]);
    c=max(b-a[i],0);
  }
  ans+=min(a[n],c);
  cout<<ans;
}