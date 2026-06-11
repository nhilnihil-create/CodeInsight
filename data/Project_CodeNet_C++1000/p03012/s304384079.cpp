#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <cmath>
#include <algorithm>
#include <iomanip>
#include <queue>
#include <string>
#include <utility>
#include <cassert>
#include <numeric>
#include <random>


using namespace std;
typedef long long ll;

ll pre[128], suf[128];
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int n;
  cin >> n;
  vector<ll> pesos;
  for (int i = 0; i < n; i++) {
    ll w;
    cin >> w;
    pesos.push_back(w);
  }


  pre[0] = pesos[0];
  for (int i = 1; i < n; i++) {
    pre[i] = pre[i-1] + pesos[i];
  }  
  suf[n-1] = pesos[n-1];
  for (int i = n-2; i >= 0; i--) {
    suf[i] = suf[i+1] + pesos[i];
  }

  ll res = 1e18;
  for (int i = 1; i < n-1; i++) {
    ll aux = abs(pre[i] - suf[i+1]);
    res = min(res, aux);
  }
  cout << res << endl;
  return 0;
}
