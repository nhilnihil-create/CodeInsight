#include<bits/stdc++.h>
#define ll long long int

using namespace std;

const ll mod=1000000007;
const ll inf=1e18;

int main(){

  ll n;
  cin >> n;
  ll l[n];
  for(ll i=0;i<n;i++)cin >> l[i];

  sort(l,l+n);
  ll s=0;

  for(ll i=0;i<n-1;i++){
    for(ll j=i+1;j<n;j++){
      ll p = lower_bound(l,l+n,l[i]+l[j])-l-1;
      s+=p-j;
    }
  }

  cout << s << endl;


}