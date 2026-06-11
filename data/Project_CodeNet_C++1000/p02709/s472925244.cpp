#include<bits/stdc++.h>
using namespace std;
#define int long long

int N;
pair<int,int> A[2000];
int dp[2001][2001];

int happiness(int i, int to) {
  return abs(A[i].second - to) * A[i].first;
}

signed main() {
  cin >> N;
  for(int i=0; i<N; i++) {
    int a; cin >> a;
    A[i] = make_pair(a, i);
  }
  sort(A, A+N, greater<pair<int,int>>());

  int ans = 0;
  for(int sum=1; sum<=N; sum++) for(int x=0; x<=sum; x++) {
    int y = sum - x;
    //cerr << x << " " << y << endl;
    if(x == 0)    dp[x][y] = dp[x][y-1] + happiness(x+y-1, N-1-y+1);
    else if(y==0) dp[x][y] = dp[x-1][y] + happiness(x+y-1, x-1);
    else          dp[x][y] = max(dp[x-1][y] + happiness(x+y-1, x-1), dp[x][y-1] + happiness(x+y-1, N-1-y+1));
    ans = max(ans, dp[x][y]);
  }
  cout << ans << endl;
}
