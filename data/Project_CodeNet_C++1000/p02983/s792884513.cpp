#include<bits/stdc++.h>
#define ll long long int

using namespace std;

const ll mod=1000000007;
const ll inf=1e18;

int main(){

  ll l,r;
  cin >> l >>r;
  if(r-l>=2019)cout << 0 << endl;
  else{
    ll m=inf;
    for(ll i=l;i<r;i++){
      for(ll j=i+1;j<=r;j++)m=min(m,i*j%2019);
    }
    cout << m << endl;
  }


}