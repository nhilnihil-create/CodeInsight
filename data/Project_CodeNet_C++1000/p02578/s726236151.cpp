#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define per(i, a, b) for(int i = a; i >= (b); --i)
#define trav(a, x) for(auto &a : x)
#define all(x) x.begin(), x.end()
#define sz(x) (int)x.size()
using ll = unsigned long long;
using pii = pair<int, int>;
using vi = vector<int>;



int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL); cout.tie(NULL);
  
  ll n; cin >> n;
  vector<ll> v(n);
  rep(i,0,n) 
    cin >> v[i];

  ll res = 0;
  for (int i = 1; i < n; i++) {
    if (v[i] < v[i-1]) {
      res += v[i - 1] - v[i];
      v[i] = v[i - 1];
    }
  }
  cout << res;
}