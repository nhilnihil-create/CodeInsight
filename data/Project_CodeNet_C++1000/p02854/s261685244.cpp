#include <bits/stdc++.h>
#include<chrono>
using namespace std;
using ll = long long;

int main() {
  ll N;
  cin >> N;
  ll L = 0; //全長
  vector<ll> A(N);
  for (int i = 0; i < N; i++) {
    ll a;
    cin >> a;
    L += a;
    A[i] = a;
  }
  vector<vector<ll>> B(2, vector<ll>(N-1));
  priority_queue<ll, vector<ll>, greater<ll>> ans;
  B[0][0] = A[0];
  B[1][0] = L - A[0];
  ans.push(abs(B[1][0] - B[0][0]));
  for (int i = 1; i <= N-2; i++) {
    B[0][i] = B[0][i-1] + A[i];
    B[1][i] = L - B[0][i];
    ans.push(abs(B[1][i] - B[0][i]));
  }
  cout << ans.top() << endl;
}

  