#include <bits/stdc++.h>
using namespace std;
int main(){
  int n,k;
  cin>>n>>k;
  vector<int> h(n);
  for(int i=0;i<n;i++)cin>>h[i];
  sort(h.begin(),h.end());
  reverse(h.begin(),h.end());
  for(int i=0;i<min(n,k);i++)h[i]=0;
  long long ans=0;
  for(int i=0;i<n;i++)ans+=h[i];
  cout<<ans<<endl;
  return 0;
}