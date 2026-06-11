#include<bits/stdc++.h>
#define ll long long int

using namespace std;

const ll mod=1000000007;
const ll inf=1e18;

int main(){

  ll n,k;
  cin >> n >> k;

  ll a[n],f[n];
  for(ll i=0;i<n;i++)cin >> a[i];
  for(ll i=0;i<n;i++)cin >> f[i];

  sort(a,a+n);
  sort(f,f+n);
  reverse(f,f+n);

  ll m=0;
  for(ll i=0;i<n;i++)m=max(m,a[i]*f[i]);

  ll r=m,l=-1;
  ll h;

  while(abs(r-l)>1){
    h=(r+l)/2;
    ll s=0;
    for(ll i=0;i<n;i++){
      ll b;
      if(h%f[i]==0) b=max((ll) 0,a[i]-h/f[i]);
      else b=max((ll) 0,a[i]-h/f[i]);
      s+=b;
    }
    if(s<=k){
      r=h;
    }
    else l=h;
  }

  cout << r << endl;

}