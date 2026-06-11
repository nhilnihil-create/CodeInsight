#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<ll> vec;
typedef vector<vec> mat;
typedef pair<ll,ll> pll;
const ll mod=1e9+7;
//const ll mod=998244353;
const ll inf=5e18;

int main() {
  ll n,k;
  cin >> n >> k;
  ll lim=n*(n-1)/2-(n-1);
  if(lim<k) {
    cout << -1 << endl;
    return 0;
  }
  cout << n-1+lim-k << endl;
  lim-=k;
  for(ll i=0;i<n-1;i++) {
    cout << 1 << " " << i+2 << endl;
  }
  ll i=2,j=3;
  while(lim--) {
    cout << i << " " << j << endl;
    j++;
    if(j>n) {
      i++;
      j=i+1;
    }
  }
}