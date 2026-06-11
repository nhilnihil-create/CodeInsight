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
  ll n,k;
  cin >> n >> k;
  k=min(k,50LL);
  vec a(n);
  for(ll i=0;i<n;i++) {
    cin >> a[i];
  }
  priority_queue<ll,vec,greater<ll>> f,t;
  ll tmp=0;
  while(k--) {
    tmp=0;
    for(ll i=0;i<n;i++) {
      f.push(i-a[i]);
      t.push(i+a[i]);
    }
    for(ll i=0;i<n;i++) {
      while(f.size()&&f.top()<=i) {
        tmp++;
        f.pop();
      }
      a[i]=tmp;
      while(t.size()&&t.top()<=i) {
        tmp--;
        t.pop();
      }
    }
    while(t.size()) t.pop();
  }
  for(ll i=0;i<n;i++) {
    if(i) cout << " ";
    cout << a[i];
  }
  cout << endl;
}