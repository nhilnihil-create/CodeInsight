#include <bits/stdc++.h>
using namespace std;
template <class T, class U>
ostream &operator<<(ostream &os, const pair<T, U> &p) {
  os << "(" << p.first << "," << p.second << ")";
  return os;
}
#ifdef __LOCAL
#define debug(x) cerr << __LINE__ << ": " << #x << " = " << x << endl
#define debugArray(x, n)                           \
  cerr << __LINE__ << ": " << #x << " = {";        \
  for (long long hoge = 0; (hoge) < (n); ++(hoge)) \
    cerr << ((hoge) ? "," : "") << x[hoge];        \
  cerr << "}" << endl
#else
#define debug(x) (void(0))
#define debugArray(x, n) (void(0))
#endif

void inc(vector<int> &num) {
  int N = num.size();
  int i = 0;
  while (i < N && (num[i] == 9 || i + 1 < N && num[i] == num[i + 1] + 1)) i++;
  if (i == N)
    num.push_back(1);
  else
    num[i]++;
  for (i--; i >= 0; i--) {
    num[i] = max(num[i + 1] - 1, 0);
  }
}

long long toll(vector<int> &num) {
  long long ret = 0;
  for (int i = num.size() - 1; i >= 0; i--) {
    ret *= 10;
    ret += num[i];
  }
  return ret;
}

signed main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  int K;
  cin >> K;
  vector<int> num;
  for (int i = 0; i < K; i++) {
    inc(num);
  }
  long long ans = toll(num);
  cout << ans << endl;
  return 0;
}
