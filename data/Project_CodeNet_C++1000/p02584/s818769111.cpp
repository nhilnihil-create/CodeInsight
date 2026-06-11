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
  ll x,k,d;
  cin >> x >> k >> d;
  x=abs(x);
  if(x/d<=k) {
    if((x+d-1)/d<=k) {
      if(x/d%2==k%2) {
        cout << x%d << endl;
      }
      else {
        cout << abs(x%d-d) << endl;
      }
    }
    else cout << x%d << endl;
  }
  else {
    cout << x-d*k << endl;
  }
}