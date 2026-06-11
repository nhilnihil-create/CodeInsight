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
  ll a,av,b,bv,t;
  cin >> a >> av >> b >> bv >> t;
  if(av>bv) {
    ll v=av-bv;
    if((abs(a-b)+v-1)/v<=t) {
      cout << "YES" << endl;
      return 0;
    }
  }
  cout << "NO" << endl;
}