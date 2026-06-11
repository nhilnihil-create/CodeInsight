#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  int n;
  cin >> n;
  int a[n];

  const int mxnum = 1000001;
  int num[mxnum];
  for (int i = 0; i < mxnum; i++) {
    num[i] = 0;
  }

  for (int i = 0; i < n; i++) {
    cin >> a[i];
    num[a[i]]++;
  }

  bool pw = true;
  for (int i = 2; i < mxnum; i++) {
    int multi_cnt = 0;
    for (int j = i; j < mxnum; j += i) {
      multi_cnt += num[j];
    }
    if (multi_cnt > 1) {
      // iの倍数が２つ以上ある
      pw = false;
      break;
    }
  }

  if (pw) {
    puts("pairwise coprime");
    return 0;
  }

  int gcd_all = 0;
  for (int i = 0; i < n; i++) {
    gcd_all = gcd(gcd_all, a[i]);
  }

  if (gcd_all == 1) {
    puts("setwise coprime");
    return 0;
  }

  puts("not coprime");
  return 0;
}