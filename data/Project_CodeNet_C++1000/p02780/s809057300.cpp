#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using namespace std;
using ll = long long int;

int main () {
  int N, K;
  cin >> N >> K;

  vector<int> p(N, 0);
  vector<int> exp(N, 0);
  vector<int> sum_exp(N + 1, 0);
  rep(i, N) {
    cin >> p[i];
    exp[i] = p[i] + 1;
  }
 
  for (int i = 0; i < N; i++) {
    sum_exp[i + 1] = sum_exp[i] + exp[i];
  }

  int max = 0;
  for (int i = 0; i + K <= N; i++) {
    if (sum_exp[i + K] - sum_exp[i] > max) max = sum_exp[i + K] - sum_exp[i];
  }
 
  cout << fixed << setprecision(10) << (double)(max) / 2;
  
}