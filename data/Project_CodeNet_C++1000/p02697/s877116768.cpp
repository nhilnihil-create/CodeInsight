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
  ll n,m;
  cin >> n >> m;
  for(ll i=0;i<(m+1)/2;i++) {
    cout << (m+1)/2-i << " " << (m+1)/2+1+i << endl;
  }
  for(ll i=0;i<m-(m+1)/2;i++) {
    cout << (m+1)/2+m-i << " " << (m+1)/2+m+2+i << endl;
  }
}