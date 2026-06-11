
#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define rrep(i, n) for (int i = 1; i <= (n); ++i)
#define drep(i, n) for (int i = (n)-1; i >= 0; --i)
using namespace std;
typedef long long ll;
typedef vector<int> VI;
typedef vector<VI> VVI;
ll INF = 1e12;

int main() {
  int N;
  ll K;
  cin >> N >> K;
  VI A(N);
  VI F(N);
  rep(i, N) { cin >> A.at(i); }
  rep(i, N) { cin >> F.at(i); }
  sort(A.begin(), A.end());
  sort(F.begin(), F.end(), greater<ll>());
  ll low = -1;
  ll high = INF;
  ll mid = (low + high) / 2;
  bool pos;
  while (low + 1 < high) {
    ll usek = 0;
    pos = true;
    rep(i, N) {
      usek += max(0ll, A.at(i) - mid / F.at(i));
      if (usek > K) {
        pos = false;
        break;
      }
    }
    if (pos) {
      high = mid;
    } else {
      low = mid;
    }
    mid = (low + high) / 2;
  }
  cout << high << endl;
  return 0;
}
