#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using namespace std;
using ll = long long int;

int main () {
  int N;
  cin >> N;

  vector<int> A(N, 0);
  vector<int> num(200001, 0);
  rep(i, N) {
    cin >> A[i];
    num[A[i]]++;
  }

  ll sum = 0;
  for (int i = 1; i <= 200000; i++) {
    sum += (pow(num[i], 2) - num[i]) / 2;
  }

  rep(i, N) cout << sum - num[A[i]] + 1 << endl;
}