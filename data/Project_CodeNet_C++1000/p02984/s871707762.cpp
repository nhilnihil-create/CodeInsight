#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  int N;
  cin >> N;
  vector<ll> dam(N);
  vector<ll> Rain(N);
  ll sum = 0;
  for (ll &e : dam) {
    cin >> e;
    sum += e;
  }
  for (int i = 0; i < N; i++) {
    if (i < 2) {
      ll s = 0;
      for (int j = 0; j < (N-1)/2; j++) s += dam[(i+1+j*2)%N];
      Rain[i] = sum-s*2;
    }
    else Rain[i] = Rain[i-2]+(dam[i-1]-dam[i-2])*2;
  }
  for (int i = 0; i < N; i++) {
    cout << Rain[i] << (i < N-1 ? " " : "\n");
  }
}