#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int main() {
  ll N, K, L = 0;
  cin >> N >> K;
  vector<int> H(N);
  for (int i = 0; i < N; i++) {cin >> H.at(i);}
  sort(H.begin(), H.end());
  if (N <= K) {cout << 0 << endl;}
  else {
    for (int i = 0; i < N - K; i++) {L += H.at(i);}
    cout << L << endl;
  }
}