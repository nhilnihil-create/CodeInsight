#include<bits/stdc++.h>
#define ll long long int

using namespace std;

const ll mod=1000000007;
const ll inf=1e18;

int main(){

  ll n;
  cin >> n;
  ll k=0;
  for(ll i=0;i<n;i++){
    ll a;
    cin >> a;
    if(a==k+1){
      k++;
    }
  }
  if(k!=0)cout << n-k << endl;
  else cout << -1 << endl;
}