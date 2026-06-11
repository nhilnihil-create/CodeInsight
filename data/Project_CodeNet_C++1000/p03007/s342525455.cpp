#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, n) for(int i = 0; i < (int)(n); i++)
const double PI = acos(-1);
const ll MOD = 1000000007;
using Graph = vector<vector<int>>;

int main() {
  int N; cin >> N;
  vector<int> A(N);
  rep(i,N) cin >> A[i];
  
  sort(A.begin(),A.end());
  vector<int> x(N-1),y(N-1);
  int ans;
  if (A[N-2] < 0) {
    ans = A[N-1];
    for (int i = 0; i < N-1; i++) {
      y[i] = ans;
      x[i] = A[i];
      ans -= A[i]; 
    }
  } else if (A[0] >= 0) {
    ans = A[0];
    for (int i = 0; i < N-1; i++) {
      if (i != N-2) {
        y[i] = ans;
        x[i] = A[i+1];
        ans -= A[i+1];
      } else {
        y[i] = A[i+1];
        x[i] = ans;
        ans = A[i+1] - ans;
      }
    }
  } else {
    int k = lower_bound(A.begin(),A.end(),0) - A.begin();
    ans = A[0];
    for (int i = N-1; i >= 1; i--) {
      if (i != k) {
        y[N-1-i] = ans;
        x[N-1-i] = A[i];
        ans -= A[i]; 
      } else {
        y[N-1-i] = A[k];
        x[N-1-i] = ans;
        ans = A[k] - ans;
      }
    }
  }
  
  cout << ans << endl;
  rep(i,N-1) cout << y[i] << " " << x[i] << endl;
}