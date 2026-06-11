#pragma region

#include <bits/stdc++.h>
using namespace std;
#define ALL(x) (x).begin(), (x).end()
#define POW2(n) (1LL << (n))
#define FOR(i, begin, end) for (int i = (begin); i < (end); i++)
#define IFOR(i, begin, end) for (int i = (end)-1; i >= (begin); i--)
#define REP(i, n) FOR(i, 0, n)
#define IREP(i, n) IFOR(i, 0, n)
#define MOD 1000000007
#define debug(x) cerr << #x << " = " << (x) << " (line: " << __LINE__ << ") " << endl;
typedef long long ll;
template <typename T>
istream &operator>>(istream &is, vector<T> &vec) {
  for (auto &v : vec) is >> v;
  return is;
}
template <typename T>
ostream &operator<<(ostream &os, const vector<T> &vec) {
  os << "vec[ ";
  REP(i, vec.size())
  i == 0
      ? os << vec[i]
      : os << ", " << vec[i];
  os << " ]";
  return os;
}
template <typename T>
ostream &operator<<(ostream &os, const deque<T> &deq) {
  os << "deq[ ";
  REP(i, deq.size())
  i == 0
      ? os << deq[i]
      : os << ", " << deq[i];
  os << " ]";
  return os;
}
template <typename T>
ostream &operator<<(ostream &os, const set<T> &set) {
  os << "{ ";
  for (auto &&s : set) &s == &(*set.begin()) ? os << s : os << ", " << s;
  os << " }";
  return os;
}
template <typename T>
ostream &operator<<(ostream &os, const unordered_set<T> &set) {
  os << "{ ";
  for (auto &&s : set) &s == &(*set.begin()) ? os << s : os << ", " << s;
  os << " }";
  return os;
}
template <typename T>
ostream &operator<<(ostream &os, const multiset<T> &set) {
  os << "{ ";
  for (auto &&s : set) &s == &(*set.begin()) ? os << s : os << ", " << s;
  os << " }";
  return os;
}
template <typename T>
ostream &operator<<(ostream &os, const unordered_multiset<T> &set) {
  os << "{ ";
  for (auto &&s : set) &s == &(*set.begin()) ? os << s : os << ", " << s;
  os << " }";
  return os;
}
template <typename T1, typename T2>
ostream &operator<<(ostream &os, const pair<T1, T2> &p) {
  os << "(" << p.first << ", " << p.second << ")";
  return os;
}
template <typename TK, typename TV>
ostream &operator<<(ostream &os, const map<TK, TV> &m) {
  os << "{ ";
  for (auto &&k : m) &k == &(*m.begin()) ? os << k.first << " => " << k.second : os << ", " << k.first << " => " << k.second;
  os << " }";
  return os;
}
template <typename TK, typename TV>
ostream &operator<<(ostream &os, const unordered_map<TK, TV> &m) {
  os << "{ ";
  for (auto &&k : m) &k == &(*m.begin()) ? os << k.first << " => " << k.second : os << ", " << k.first << " => " << k.second;
  os << " }";
  return os;
}

#pragma endregion

bool isCollided(vector<vector<bool>> &map, int h, int w, int x, int y) {
  REP(i, w)
  REP(j, h)
  if (map[y + j][x + i]) return true;
  return false;
}

int find(string &S, char c, int offset) {
  FOR(i, offset, S.size()) {
    if (S[i] == c) {
      return i;
    }
  }
  return -1;
}

int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  cout << fixed << setprecision(10);

  ll T1, T2, A1, A2, B1, B2;
  cin >> T1 >> T2 >> A1 >> A2 >> B1 >> B2;

  if (A1 < B1) {
    swap(A1, B1);
    swap(A2, B2);
  }

  if (A2 > B2) {
    cout << "0\n";
    return 0;
  }
  if (A1 * T1 + A2 * T2 == B1 * T1 + B2 * T2) {
    cout << "infinity\n";
    return 0;
  }
  if (A1 * T1 + A2 * T2 > B1 * T1 + B2 * T2) {
    cout << "0\n";
    return 0;
  }

  ll min = 0, max = 1e18;
  __int128_t p;
  while (max - min > 1) {
    ll m = (min + max) / 2;
    p = A1 * T1 - B1 * T1 + (__int128_t)(A1 * T1 - B1 * T1 + A2 * T2 - B2 * T2) * m > 0;
    if (p > 0) {
      min = m;
    } else {
      max = m;
    }
  }
  p = A1 * T1 - B1 * T1 + (__int128_t)(A1 * T1 - B1 * T1 + A2 * T2 - B2 * T2) * max;
  cout << (p == 0 ? min * 2 + 2 : min * 2 + 1) << "\n";
}
