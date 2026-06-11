#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> pll;

int main() {
  int n;
  cin >> n;
  vector<ll> a(n);
  vector<pll> outputs;
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  sort(a.begin(), a.end());
  ll max = a[n - 1];
  ll min = a[0];
  for (int i = 1; i < n - 1; i++) {
    if (a[i] > 0) {
      outputs.push_back(pll(min, a[i]));
      min -= a[i];
    } else {
      outputs.push_back(pll(max, a[i]));
      max -= a[i];
    }
  }
  outputs.push_back(pll(max, min));
  cout << max - min << endl;
  for (int i = 0; i < outputs.size(); i++) {
    cout << outputs[i].first << " " << outputs[i].second << endl;
  }
}
