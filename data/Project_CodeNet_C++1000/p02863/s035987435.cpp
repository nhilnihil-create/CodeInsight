// C++ 14
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define loop(__x, __start, __end) for(int __x = __start; __x < __end; __x++)
#define chmax(x,y) (x = max(x, y))
void solve(); int main() { solve(); return 0; }

// dp[i][j] := i個目までで容量がj以下の時の最大の価値.
int dp[3100][6100];

typedef tuple<int,int> P;

void solve() {
  int n, c; cin >> n >> c;
  vector<P> A;
  loop(i,0,n) {
    int a, b; cin >> a >> b;
    A.emplace_back(a, b);
  }
  sort(A.begin(), A.end());
  
  int max_ = 0;
  loop(i,0,n) {
    int a, b;
    tie(a, b) = A[i];
    loop(j,0,c+1) {
      chmax(dp[i+1][j], dp[i][j]);
      chmax(dp[i+1][j+a], dp[i][j] + b);
    }
  }
  
  loop(k,0,n) { // 最後に取る要素を全探索
    int score = get<1>(A[k]);
    if (k>0) score += dp[k][c-1]; // Aは時間昇順にソート済みなので、dp[k-1][c-1]には最後の注文が出来る時間までにk以外を使った最大価値に入っている.
    max_ = max(max_, score);
  }
  cout << max_ << endl;
}
