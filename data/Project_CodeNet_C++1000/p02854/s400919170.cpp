#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
ll prefix[200009];
int main() {
  int n;cin>>n;
  ll sum=0;
  for(int i=1;i<=n;i++){
      int x;
      cin>>x;
      sum+=x;
      prefix[i]=x+prefix[i-1];
  }
  ll ans=3020202020;
  
   for(ll i=1;i<n;i++){
       ll l=prefix[i];
       ll r=sum-prefix[i];
      ans=min(abs(l-r),ans);
  }
  cout<<ans;
}