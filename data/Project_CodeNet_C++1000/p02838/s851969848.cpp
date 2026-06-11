#include<bits/stdc++.h>
#define ll long long int

using namespace std;

const ll mod=1000000007;
const ll inf=1e18;

ll powmod(ll a,ll n,ll m) {
    if(n == 0)
        return 1;

    if(n % 2 ==0){
        ll r = powmod(a,n/2,m);
        return r*r % m;
    }

    return a*powmod(a,n-1,m)%m;
}

int main(){

  ll n;
  cin >> n;
  ll a[n];
  for(ll i=0;i<n;i++)cin >> a[i];

  ll s=0;

  for(ll i=0;i<61;i++){
    ll b=0,c=0;
    for(ll j=0;j<n;j++){
      if(a[j] & (1LL<<i))b++;
      //if(a[j]>>i & 1)b++;
      else c++;
    }
    //if(i==0)cout << b <<" " << c << endl;
    ll d=powmod(2,i,mod);
    d*=b;
    d%=mod;
    d*=c;
    d%=mod;
    s+=d;
    s%=mod;
    //if(b*c!=0)cout << b << " " << c << endl;
  }

  cout << s << endl;

}