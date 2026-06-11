#include <bits/stdc++.h>
using namespace std;
int main(){
  int n;
  cin>>n;
  vector<int> a(n+1),b(n);
  for(int i=0;i<n+1;i++)cin>>a[i];
  for(int i=0;i<n;i++)cin>>b[i];
  long long ans=0;
  for(int i=0;i<n;i++){
    int p=min(a[i],b[i]);
    ans+=p;
    a[i]-=p;
    b[i]-=p;
    int q=min(a[i+1],b[i]);
    ans+=q;
    a[i+1]-=q;
    b[i]-=q;
  }
  cout<<ans<<endl;
  return 0;
}