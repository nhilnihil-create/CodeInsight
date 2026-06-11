#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i = 0; i < (n);i++)
#define sz(x) int(x.size())
typedef long long ll;
typedef pair<int,int> P;

int main(){ 
  int n;
  cin >> n;
  vector<ll> a(n + 1);
  rep(i,n + 1) cin >> a[i];
  if (n == 0) {
    if (a[0] == 1) {
      cout << 1 << endl;
    } else {
      cout << -1 << endl;
    }
    return 0;
  }
  if (a[0] != 0) {
    cout << -1 << endl;
    return 0;
  }

  vector<ll> cum(n + 2, 0);
  for (int i = n; i >= 0; i--) cum[i] = cum[i + 1] + a[i];

  ll node = 1;
  ll res = 1;

  for (int i = 0; i < n; i++) {
    if (node * 2 < a[i + 1]) {
      cout << -1 << endl;
      return 0;
    }
    
    node = min(node * 2, cum[i + 1]);
    res += node;
    node -= a[i + 1];
  }
 
  cout << res << endl;
  return 0;
} 