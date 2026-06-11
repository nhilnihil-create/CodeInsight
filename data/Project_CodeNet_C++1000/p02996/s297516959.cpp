#include <bits/stdc++.h>
#define F first
#define S second
using namespace std;
using ll = long long;
typedef pair<ll, ll> P;
ll Mod = 1000000007;
int main() {
  int N;
  cin >> N;
  vector<P> work(N);
  bool ans = true;
  for (int i = 0; i < N; i++) {
    cin >> work[i].S >> work[i].F;
  }
  sort(work.begin(),work.end());
  ll R[N];
  R[0] = work[0].S;
  for (int i = 1; i < N; i++) {
    R[i] = R[i-1] + work[i].S;
  }
  for (int i = 0; i < N; i++) {
    if (R[i] > work[i].F) {
      ans = false;
    }
  }
  if (ans) {
    cout << "Yes" << endl;
  } else {
    cout << "No" << endl;
  }
  return 0;
}