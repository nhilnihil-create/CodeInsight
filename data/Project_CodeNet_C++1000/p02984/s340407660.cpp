#include <algorithm>
#include <cmath>
#include <cstdio>
#include <functional>
#include <iostream>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <vector>
using namespace std;
using ll = long long;
int main() {
  int n;
  cin >> n;
  vector<ll> a(n), b(n + 1, 0);
  for(int i = 0; i < n; i++) {
    cin >> a[i];
  }
  reverse(a.begin(), a.end());
  a.push_back(a[0]);
  reverse(a.begin(), a.end());

  ll sum = 0;
  for(int i = 1; i <= n; i++) {
    sum *= -1;
    sum += a[i] * 2;
  }
  b[1] = sum / 2;
  for(int i = 2; i <= n; i++) {
    b[i] = a[i - 1] * 2 - b[i - 1];
  }
  for(int i = 1; i <= n; i++) {
    cout << b[i] << " ";
  }
  cout << endl;
  return 0;
}