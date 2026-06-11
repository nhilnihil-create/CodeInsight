#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <map>
#include <set>
#include <queue>

#define rep(i,n) for (int i = 0; i < (n); ++i)

using namespace std;

typedef long long ll;

int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);

  ll n;
  cin >> n;

  vector<ll> a(n);

  ll sum_v = 0;

  rep(i, n) {
    cin >> a[i];
    sum_v += abs(a[i]);
  }

  sort(a.begin(), a.end());

  ll p_idx = -1;

  rep(i, n) {
    if (a[i] >= 0) {
      p_idx = i;
      break;
    }
  }

  ll cur = a[0];

  // if all plus
  if ( p_idx == 0 ) {
    cout << sum_v - 2*a[0] << endl;
    for ( int i = 1; i < n-1; i++) {
      cout << cur << " " << a[i] << endl;
      cur -= a[i];
    }
    cout << a[n-1] << " " << cur << endl;
    return 0;
  }

  // if all minus
  if ( p_idx == -1 ) {
    cur = a[n-1];
    cout << sum_v + 2*a[n-1] << endl;
    for ( int i = 0; i < n-1; i++) {
      cout << cur << " " << a[i] << endl;
      cur -= a[i];
    }
    return 0;
  }
  
  cout << sum_v << endl;

  for (int i = p_idx; i < n-1; i++) {
    cout << cur << " " << a[i] << endl;
    cur -= a[i];
  } 

  for (int i = 0; i < p_idx; i++) {
    if ( i == 0 ) {
      cout << a[n-1] << " " << cur << endl;
      cur = a[n-1] - cur;
    } else {
      cout << cur << " " << a[i] << endl;
      cur -= a[i];
    }
  }

  return 0;
}