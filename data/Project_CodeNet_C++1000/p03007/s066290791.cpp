#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
typedef long long ll;
typedef pair<ll, ll> P;

const int MAXN = 100010;
int n;
int A[MAXN];

void solve() {
  sort(A, A+n);
  ll ans = 0;
  vector<P> v;
  ll cur;
  if (A[n-1] < 0) {
    cur = A[n-1];
    for (int i=0;i<n-1;i++) {
      v.push_back(P(cur, A[i]));
      cur -= A[i];
    }
  } else if (A[0] > 0) {
    cur = A[0];
    for (int i=1;i<n-1;i++) {
      v.push_back(P(cur, A[i]));
      cur -= A[i];
    }
    v.push_back(P(A[n-1], cur));
    cur = A[n-1] - cur;
  } else {
    cur = A[n - 1];
    int i = 1;
    while (A[i] < 0) {
      v.push_back(P(cur, A[i]));
      cur -= A[i++];
    }
    ll cur2 = A[0];
    while (i < n - 1) {
      v.push_back(P(cur2, A[i]));
      cur2 -= A[i++];
    }
    v.push_back(P(cur, cur2));
    cur -= cur2;
  }
  cout << cur << endl;
  for (int i=0;i<v.size();i++) {
    cout << v[i].first << " " << v[i].second << endl;
  }
}

int main() {
  cin >> n;
  for (int i=0;i<n;i++) {
    cin >> A[i];
  }
  solve();
}
