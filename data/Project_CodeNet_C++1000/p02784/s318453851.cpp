#include<bits/stdc++.h>
#define ll long long int

using namespace std;

const ll mod=1000000007;
const ll inf=1e18;

int main(){

  ll h,n,s=0;
  cin >> h >> n;

  for(ll i=0;i<n;i++){
    ll a;
    cin >> a;
    s+=a;
  }

  if(s>=h)cout << "Yes" << endl;
  else cout << "No" << endl;

}