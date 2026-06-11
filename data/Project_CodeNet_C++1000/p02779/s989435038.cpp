#include<bits/stdc++.h>
#define ll long long int

using namespace std;

const ll mod=1000000007;
const ll inf=1e18;

int main(){

  ll n;
  cin >> n;
  set<ll> v;

  for(ll i=0;i<n;i++){
    ll a;
    cin >> a;
    v.insert(a);
  }

  if(v.size()==n)cout << "YES" << endl;
  else cout << "NO" << endl;

}