#include<bits/stdc++.h>
#define ll long long int

using namespace std;

const ll mod=1000000007;
const ll inf=1e18;

ll sousa(ll a){
  ll c=0;
  ll b=a;
  while(b%2==0){
    c++;
    b/=2;
  }
  return c;
}

ll gcd(ll a,ll b){
  if(a%b == 0){
    return b;
  }else{
    return gcd(b, a%b);
  }
}

ll lcm(ll a,ll b){
  ll c;
  c=a/gcd(a,b)*b;
  return c;
}

int main(){

  ll n,m;
  cin >> n >> m;
  ll a[n];
  for(ll i=0;i<n;i++)cin >> a[i];

  ll b=sousa(a[0]);
  bool ok=true;

  for(ll i=1;i<n;i++){
    if(b!=sousa(a[i])){
      ok=false;
      break;
    }
  }

  if(!ok)cout << 0 << endl;
  else{
    for(ll i=0;i<n;i++)a[i]/=2;
    ll l=1;
    for(ll i=0;i<n;i++){
      l=lcm(l,a[i]);
      if(m<l){
        cout << 0 << endl;
        return 0;
      }
    }

    if(m<l)cout << 0 << endl;
    else cout << 1+(m-l)/(2*l) << endl;

  }


}