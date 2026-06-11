#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

#define rep(i, N) for (int i = 0; i < (int)N; i++)
const ll MOD = pow(10,9)+7;
const ll LLINF = pow(2,61)-1;
const int INF = pow(2,29)-1;


int main() {
  int N; cin >> N;
  ll A[max(100,N)]={}; rep(i,N) cin >> A[i];
  ll sum = 0; rep(i,N) sum ^= A[i];

  int count = 0;
  for (int i=60; i>=0; i--) {
    if (count==N) break;
    if (sum&(1ull<<i)) continue;
    int m = 0, pos = -1;
    for (int j=count; j<N; j++) {
      if (A[j]&(1ull<<i) && A[j]>m) {
        m = A[j];
        pos = j;
      }
    }
    if (pos==-1) continue;
    swap(A[count],A[pos]);
    rep(j,N) if (A[j]&(1ull<<i) && j!=count) A[j] ^= A[count];
    count++;
    // cout << i << ": " << m << endl;
    // rep(i,N) cout << A[i] << " "; cout << endl;
  }
  ll r = 0; rep(i,N) r ^= A[i];
  ll result = (r&~sum)*2 + sum;
  cout << result << endl;
  return 0;
}