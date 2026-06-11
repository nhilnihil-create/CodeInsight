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
  bool t = false;
  for (int i = 1; i <= N; i++) {
    int price = i * 108;
    if (price /100 == N){
      cout << i << endl;
      return 0;
      t = true;
    }
  }
  if(!t){
    cout << ":(" << endl;
  }
}