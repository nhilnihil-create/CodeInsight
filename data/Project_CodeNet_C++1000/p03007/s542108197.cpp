#include <iostream>
#include <vector>
#include <algorithm>
#include <sstream>

using namespace std;
using ll = long long;

#define all(a) (a).begin(),(a).end()
#define loop(i,a,b) for(int i=(a);i<(b);++i)
#define rep(i,n) for(int i=0;i<(n);++i)
#define in(v) cin>>v;
#define out(v) cout<<v<<"\n"

int main() {
  cin.tie(0); ios::sync_with_stdio(false);
  int N; in(N);

  vector<ll> A(N);
  rep(i, N) {
    in(A[i]);
  }
  sort(all(A));
  if (A[0] > 0) {
    ll sum = -A[0];
    loop(i, 1, N) {
      sum += A[i];
    }
    out(sum);
    sum = A[0];
    loop(i, 1, N-1) {
      out(sum << " " << A[i]);
      sum -= A[i];
    }
    out(A[N-1] << " " << sum);
  } else {
  // } else if (A[N-1] >= 0) {
    reverse(all(A));
    ll sum = A[N-1];
    stringstream ss;
    loop(i, 1, N-1) {
      if (A[i] < 0) {
        ss << A[0] << " " << A[i] << "\n";
        A[0] -= A[i];
      } else {
        ss << sum << " " << A[i] << "\n";
        sum -= A[i];
      }
    }
    out(A[0] - sum);
    cout << ss.str();
    out(A[0] << " " << sum);
  }
  return 0;
}
