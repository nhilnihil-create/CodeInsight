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
  ll n;
  cin >> n;
  mat a(n,vec(n-1));
  for(ll i=0;i<n;i++) {
    for(ll j=0;j<n-1;j++) {
      cin >> a[i][j];
      a[i][j]--;
    }
  }
  vec bn(n);
  set<ll> end;
  ll ans=0;
  queue<ll> q;
  for(ll i=0;i<n;i++) {
    q.push(i);
  }
  while(end.size()<n&&q.size()) {
    ans++;
    q.push(n);
    set<ll> al;
    while(1) {
      ll i=q.front();
      q.pop();
      if(i==n) break;
      if(al.count(i)) continue;
      if(end.count(i)) continue;
      ll op=a[i][bn[i]];
      if(al.count(op)) continue;
      if(a[op][bn[op]]==i) {
        al.insert(i);
        al.insert(op);
        q.push(i);
        q.push(op);
        bn[i]++;
        bn[op]++;
        if(bn[i]==n-1) {
          end.insert(i);
        }
        if(bn[op]==n-1) {
          end.insert(op);
        }
      }
    }
    if(!al.size()||ans>1000000) {
      cout << -1 << endl;
      return 0;
    }
  }
  cout << ans << endl;
}