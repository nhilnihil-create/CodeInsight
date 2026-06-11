#include <bits/stdc++.h>
using namespace std;
using ll = long long;
// https://atcoder.jp/contests/abc172/tasks/abc172_d

int main() {
  int n;
  ll ans = 0, sum = 0;
  cin >> n;

  for (int i = 1; i <= n; i++) {
    ll e = n / i;
    ll l = e * i;
    sum += (i + l) * e / 2; 
  }  
  cout << sum << endl;
}