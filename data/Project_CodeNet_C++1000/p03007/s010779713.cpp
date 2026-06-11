#include <iostream>
#include <iomanip>
#include <vector>
#include <cmath>
#include <algorithm>
#include <iomanip>
#include <cstring>
#include <map>
#include <queue>

#define rep(i, N) for (int i = 0; i < (int)N; i++)
using namespace std;
typedef long long ll;
const ll LLINF = 9223372036854775807;
const int INF = pow(2,29);
const int MOD = 1000000007;

int main() {
  int N; cin >> N;
  int A[N]; rep(i, N) cin >> A[i];
  sort(A,A+N);
  priority_queue<int> m, z;
  priority_queue<int, vector<int>, greater<int>> p;

  int result = 0;
  vector<vector<int>> op;
  if (N!=2){
    rep(i, N) { 
      if (A[i]>0) p.push(A[i]);
      else if (A[i]==0) z.push(A[i]);
      else m.push(A[i]);
    }
    if (p.empty()) {
      if (!z.empty()) {
        while(!z.empty()) { p.push(z.top()); z.pop(); }
      }
      else {
        int x; x = m.top(); m.pop();
        int y; y = m.top(); m.pop();
        op.push_back({x, y});
        p.push(x-y);
      }
    }
    else if (m.empty()) {
      if (!z.empty()) {
        while(!z.empty()) { m.push(z.top()); z.pop(); }
      }
      else {
        int x; x = p.top(); p.pop();
        int y; y = p.top(); p.pop();
        op.push_back({x, y});
        m.push(x-y);
      }
    }
    else while(!z.empty()) { p.push(z.top()); z.pop(); }

    int rp = p.top(); p.pop();
    int rm = m.top(); m.pop();
    while(!p.empty()) {
      op.push_back({rm, p.top()});
      rm -= p.top();
      p.pop();
    }
    while(!m.empty()) {
      op.push_back({rp, m.top()});
      rp -= m.top();
      m.pop();
    }
    result = rp - rm;
    op.push_back({rp, rm});
  }
  else {
    result = max(A[0],A[1]) - min(A[0], A[1]);
    op.push_back({max(A[0],A[1]), min(A[0], A[1])});
  }

  cout << result << endl;
  for (auto x: op) cout << x[0] << " " << x[1] << endl;
  return 0;
}