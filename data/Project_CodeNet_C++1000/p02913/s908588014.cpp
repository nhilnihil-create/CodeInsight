// C++ 14
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define loop(__x, __start, __end) for(int __x = __start; __x < __end; __x++)
void solve(); int main() { solve(); return 0; }

int dp[5005][5005];

void solve() {
  int n;
  string s;
  cin >> n >> s;
  for (int i=n-1; i>=0; i--) {
    for (int j=n-1; j>=0; j--) {
      if (s[i]!=s[j]) { dp[i][j] = 0; continue; }
      dp[i][j] = dp[i+1][j+1] + 1;
    }
  }
  
  int max_ = 0;
  for (int i=n-1; i>=0; i--) {
    for (int j=n-1; j>=0; j--) {
      if (i>=j) continue;
      max_ = max(max_, min(dp[i][j], j-i));
    }
  }
  cout << max_ << endl;
}
