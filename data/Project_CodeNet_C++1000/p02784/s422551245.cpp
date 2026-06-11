#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<ll> vec;
typedef vector<vec> mat;
typedef pair<ll,ll> pll;
const ll mod=1e9+7;
//const ll mod=998244353;
const ll inf=1LL<<61;

int main() {
  ll n,h;
  cin >> h >> n;
  ll s=0;
  for(ll i=0;i<n;i++) {
    ll tmp;
    cin >> tmp;
    s+=tmp;
  }
  if(s>=h) cout << "Yes" << endl;
  else cout << "No" << endl;
}