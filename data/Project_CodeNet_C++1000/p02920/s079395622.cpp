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
  ll n;
  cin >> n;
  multiset<ll> s;
  for(ll i=0;i<(1<<n);i++) {
    ll tmp;
    cin >> tmp;
    s.insert(tmp);
  }
  auto f=s.end();
  f--;
  vec al,cur;
  al.push_back(*f);
  s.erase(f);
  for(ll i=0;i<n;i++) {
    for(ll j:al) {
      auto k=s.lower_bound(j);
      if(k==s.begin()) {
        cout << "No" << endl;
        return 0;
      }
      k--;
      cur.push_back(*k);
      s.erase(k);
    }
    for(auto j:cur) {
      al.push_back(j);
    }
    cur.clear();
  }
  cout << "Yes" << endl;
}