#include<bits/stdc++.h>
using namespace std;
#define ll long long
int mod=1000000007;


int main()
{

  ios::sync_with_stdio(0);
  cin.tie(0);
  ll n,m,k;
  cin>>n>>m>>k;
  vector<ll> a(n+1,0);
  vector<ll> b(m+1,0);
  for(int i=1; i<=n; i++){
        cin>>a[i];
        a[i]=a[i]+a[i-1];

  }
  for(int i=1; i<=m; i++){
        cin>>b[i];
        b[i]=b[i]+b[i-1];
  }
  ll ans=0,j=m;
  for(int i=0; i<=n; i++){
    if(a[i]>k){break;}
    while(b[j]>k-a[i]){j=j-1;}
    ans=max(ans,(ll)i+j);
  }
   cout<<ans;
  return 0;
}