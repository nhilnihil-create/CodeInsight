#include <bits/stdc++.h>
using namespace std;
#define REP(i, n) for (int i = 0; i < (int)(n); i++)
#define FOR(i, a, b) for (int i = (a); i < (b); ++i)
typedef long long ll;
typedef pair<int, int> P;
const int INF = 100100100;
const int MOD = (int)1e9 + 7;
const double EPS = 1e-9;
struct Edge {
  ll to;
  ll cost;
};
int main() {
  int N;
  cin >> N;
  vector<long double> v(N);
  REP(i, N) cin >> v[i];
  sort(v.begin(), v.end(),greater<long double>());
  while (1 < v.size()) {
    long double a = v[v.size()-1], b = v[v.size()-2];
    v.resize(v.size() - 2);
    v.push_back((a + b) / 2);
    sort(v.begin(), v.end(), greater<long double>());
  }
  cout <<fixed<<setprecision(6)<< v[0] << endl;
}