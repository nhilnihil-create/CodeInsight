#include <bits/stdc++.h>
using namespace std;
#define REP(i, n) for (int i = 0; i < (int)(n); i++)
typedef long long ll;
typedef pair<int, int> P;
const int INF = 1e9;
int main() {
  ll N;
  cin >> N;
  vector<ll> A(N);
  map<ll, ll> mp{};
  REP(i, N) cin >> A[i], mp[A[i]]++;
  if (mp.size() == 1) {
    if (mp[0] != 0) {
      cout << "Yes" << endl;
      return 0;
    }
  }
  if (mp.size() == 2 && N % 3 == 0) {
    ll tmp = 0;
    for (auto s : mp) {
      if (s.first != 0) tmp = s.second;
    }
    if (mp[0] * 3 == N && tmp * 3 / 2 == N) {
      cout << "Yes" << endl;
      return 0;
    }
  }
  if (mp.size() == 3 && N % 3 == 0) {
    vector<ll> a(0);
    for (auto s : mp) {
      a.push_back(s.first);
      if (s.second != N / 3) {
        cout << "No" << endl;
        return 0;
      }
    }
    if (((a[0] ^ a[1]) ^ a[2]) == 0) {
      cout << "Yes" << endl;
      return 0;
    }
  }
  cout << "No" << endl;
}