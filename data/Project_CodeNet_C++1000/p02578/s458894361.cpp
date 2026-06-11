#include <bits/stdc++.h>
using namespace std;
using ll=long long;
#define rep(i,n) for(int i=0;i<n;i++)
int main() {
  int n;
  cin>>n;
  vector<ll>a(n);
  for(int i=0;i<n;i++)
    cin>>a[i];
  ll ans=0;
  ll maxi=a[0];
  for(int i=1;i<n;i++){
    if(maxi>a[i])
      ans+=maxi-a[i];
    else 
      maxi=a[i];
  }
  cout<<ans<<endl;
}