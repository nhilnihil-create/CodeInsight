
#include <iostream>
#include <cstdio>
#include <cmath>
#include <string>
#include <vector>
#include <queue>
using namespace std;
#define REP(i, n) for(int i = 0; i < (int)(n); ++i)

typedef long long ll;

char s[100000+10];
int dp[100000+10];
const int INF = 1000000;

int main(void) {
  int n, m;
  scanf("%d%d%s", &n, &m, s);
  queue<int> q;
  dp[n] = 0;
  q.push(n);
  for(int i = n-1; i >= 0; --i) {
    while(!q.empty() && q.front() > i+m) {
      q.pop();
    }
    if(s[i] == '1' || q.empty()) {
      dp[i] = INF;
      continue;
    }
    dp[i] = dp[q.front()] + 1;
    q.push(i);
  }
  if(dp[0] == INF) {
    puts("-1");
    return 0;
  }
  // REP(i, n+1) {
  //   cerr << dp[i] << endl;
  // }
  for(int cur = 0; cur != n; ) {
    int next = cur+1;
    while(dp[next] != dp[cur]-1) {
      ++next;
    }
    printf("%d%c", next-cur, next == n ? '\n' : ' ');
    cur = next;
  }

  return 0;
}
