#include <bits/stdc++.h>
using namespace std;

#define int long long

signed main(){
  int n;cin>>n;
  vector<int> v(n);
  for(int i=0;i<n;i++)cin>>v[i];
  sort(v.rbegin(),v.rend());
  int ans=0,now=0;
  for(int i=1;i<n;i++){
    ans+=v[now];
    if(i&1)now++;
  }
  cout<<ans<<endl;
}
