#include <bits/stdc++.h>
using namespace std;
int main(){
  int n;
  cin>>n;
  long long ans=0;
  map<long long,long long> mp;
  for(int i=0;i<n;i++){
    int a;
    cin>>a;
    mp[a]++;
    ans+=a;
  }
  int q;
  cin>>q;
  vector<int> b(q),c(q);
  for(int i=0;i<q;i++)cin>>b[i]>>c[i];
  for(int i=0;i<q;i++){
    mp[c[i]]+=mp[b[i]];
    ans-=b[i]*mp[b[i]];
    ans+=c[i]*mp[b[i]];
    mp[b[i]]=0;
    cout<<ans<<endl;
  }
  return 0;
}
