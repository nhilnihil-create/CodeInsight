#include <bits/stdc++.h>
#include<iostream>
#include<algorithm>
#include<vector>
#include<stdio.h>
#include<cstring>
#include<math.h>
#include<map>
#include<bitset>
#include<iomanip>
#include<queue>
#include<functional>
#include<stack>
#include<tuple>
#include<cassert>
using namespace std;

#define rep(i, n) for (int i = 0; i < (int)(n); ++i)
using P = pair<int, int>;

int main() {
  float N;
  float a[100];
  float sum = 0;
  cin >> N;
  rep(i, N) {
    cin >> a[i];
  }
  rep(i, N) {
    sum += a[i];
  }
  int avr = round(sum / N);
  int ans = 0;
  rep(i, N) {
    ans += (a[i] - avr) * (a[i] - avr);
    // cout << ans << " ";
  }
  // cout << endl;
  // cout << avr << endl;
  cout << ans << endl;
  return 0;
}