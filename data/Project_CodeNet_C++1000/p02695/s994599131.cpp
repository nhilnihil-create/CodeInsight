#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
using namespace std;

struct query {
  int a, b, c, d;
};
struct manyReq {
  int n, m;
  vector<query> q;
  int ans = 0;

  manyReq(int n, int m, vector<query> q) : n(n), m(m), q(q) {}

  int get_score(vector<int> &A) {
    int s = 0;
    for (query qi : q) {
      if (A.at(qi.b) - A.at(qi.a) == qi.c) s += qi.d;
    }
    return s;
  }

  void dfs(vector<int> A) {
    if (A.size() == (unsigned int)n + 1) {
      int now = get_score(A);
      ans = max(ans, now);
      return;
    }

    A.push_back(A.back());
    while (A.back() <= m) {
      dfs(A);
      A.back()++;
    }
  }
};


int main() {
  int n, m, q;
  cin >> n >> m >> q;
  vector<query> Q(q);
  for (auto &qi : Q) {
    cin >> qi.a >> qi.b >> qi.c >> qi.d;
  }
  manyReq mr(n, m, Q);
  mr.dfs(vector<int>(1, 1));
  cout << mr.ans << endl;

  return 0;
}
