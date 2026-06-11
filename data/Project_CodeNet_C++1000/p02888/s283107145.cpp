#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main () {
  int n;
  ll ans = 0;
  cin>>n;
  ll a[10000];
  for(int i=0;i<n;i++)cin>>a[i];
  sort(a,a+n);
  for(int i=0;i<n-2;i++){
    for(int j=i+1;j<n-1;j++){
        ll r=a[i]+a[j];
        ll u=lower_bound(a,a+n,r)-a;
       ans+=u-(j+1);
    }
  }
  
    cout<<ans<<endl;
}