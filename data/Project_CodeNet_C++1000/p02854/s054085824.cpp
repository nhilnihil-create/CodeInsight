#include <bits/stdc++.h>
#include <stdlib.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
typedef pair<ll,ll> llP;

int main() {
  int n;
  cin>>n;
  ll a[n],sum[n];
  for(int i=0;i<n;i++){
    cin>>a[i];
    if(i==0){
      sum[i]=a[i];
    }
    else sum[i]=sum[i-1]+a[i];
  }
  ll ans=1e18;
  for(int i=0;i<n-1;i++){
    ans=min(ans,abs((sum[n-1]-sum[i])-sum[i]));
  }
  cout<<ans<<endl;
  return 0;
}
