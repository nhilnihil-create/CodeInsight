#include<bits/stdc++.h>
#define ll long long int

using namespace std;

const ll mod=1000000007;
const ll inf=1e18;

int main(){

  ll n,k;
  cin >> n>>k;
  ll h[n];
  for(ll i=0;i<n;i++)cin >> h[i];

  sort(h,h+n);

  ll s=0;
  for(ll i=0;i<n-k;i++){
    s+=h[i];
  }

  cout << s << endl;

}