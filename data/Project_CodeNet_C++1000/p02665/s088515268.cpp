#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, n) for (ll i = 0; i < (ll)(n); i++)
ll ans = 0;

int main()
{
ll n ;
cin >> n ;
vector<ll> a(n+1);
rep(i, n+1){
  cin >> a[i];
}
vector<ll> aa(n+1);
aa[n]=a[n];
rep(i,n)aa[n-i-1]=aa[n-i]+a[n-i-1];
aa[0]=1;

rep(i,n){
  if(aa[i]-a[i]<=0){cout << -1 << endl;return 0;}
  else if((aa[i]-a[i])*2<a[i+1]){cout << -1 << endl;return 0;}
  else aa[i+1]=min(aa[i+1],(aa[i]-a[i])*2);
}
if(a[n]!=aa[n]){cout << -1 << endl;return 0;}
for(auto r:aa)ans+=r;
cout << ans << endl;
return 0;
}