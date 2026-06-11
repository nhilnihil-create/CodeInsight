#include <bits/stdc++.h>
using namespace std;
int main(){
  int k,n;
  cin>>k>>n;
  vector<int> a(n);
  vector<int> dist;
  for(int i=0;i<n;i++)cin>>a[i];
  for(int i=0;i<n;i++){
    if(i==n-1){
      dist.push_back(a[0]+k-a[i]);
      break;
    }
    dist.push_back(a[i+1]-a[i]);
  }
  sort(dist.begin(),dist.end());
  long long ans=0;
  for(int i=0;i<n-1;i++)ans+=dist[i];
  cout<<ans<<endl;
  return 0;
}
    