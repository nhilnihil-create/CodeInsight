#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int main () {
  int N;
  ll K;
  cin >> N >> K;
  vector<ll>A(N);
  vector<ll>F(N);
  for (int i = 0; i < N; i ++) cin >> A[i];
  for (int i = 0; i < N; i ++) cin >> F[i];
  sort(A.begin(), A.end());
  sort(F.begin(), F.end());
  reverse(A.begin(), A.end());
  ll ma = 1e13;
  ll mi = 0;
  while (ma != mi) {
    ll mu = (ma + mi) / 2;
    ll k = K;
    bool can = true;
    for (int i = 0; i < N; i ++) {
      if (A[i] * F[i] > mu) {
        //cout << 'r' << ' ';
        ll kj = (A[i] * F[i]) - mu;
        kj = ((kj - 1) / F[i]) + 1;
        k -= kj;
        if (k < 0) can = false;
      }
      if (!can) break;
    }
    if (can) ma = mu;
    else mi = mu + 1;
    //cout << endl;
    //cout << ma << ' ' << mi << endl;
  }
  cout << mi << endl;
}

