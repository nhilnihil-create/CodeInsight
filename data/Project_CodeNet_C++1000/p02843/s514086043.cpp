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
  ll x;
  cin >> x;
  ll v=x/100;
  x%=100;
  if(x<=v*5) cout << 1 << endl;
  else cout << 0 << endl;
}