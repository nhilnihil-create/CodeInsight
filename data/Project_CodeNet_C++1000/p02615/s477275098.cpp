#include <bits/stdc++.h>
using namespace std;
int main(){
  int n;
  cin>>n;
  vector<int> a(n);
  for(int i=0;i<n;i++)cin>>a[i];
  sort(a.begin(),a.end());
  reverse(a.begin(),a.end());
  long long ans=a[0];
  int t=1;
  for(int i=1;i<n-1;i++){
    if(t==n-1)break;
    for(int j=0;j<2;j++){
      ans+=a[i];
      t++;
      if(t==n-1)break;
    }
  }
  cout<<ans<<endl;
  return 0;
}