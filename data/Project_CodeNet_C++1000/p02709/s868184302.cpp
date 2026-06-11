#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int MOD = 1e9 + 7;

int N;
pair<int,int> P[2020];
ll dp[2020][2020];

int main() {
	cin >> N;
  vector<pair<int, int> > P(N);
	for(int i = 0; i < N; i++) {
    int x;
		cin >> x;
		P[i] = make_pair(x, i);
	}
	
	sort(P.begin(), P.end(), greater<pair<int, int> >());
	
	for(int x = 0; x < N+1; x++) {
    for(int y = 0; y < N+1; y++) {
      dp[x][y] = -1LL<<60;
    }
  }

	dp[0][0] = 0;
  // i: すでに配置した人数
	for(int i = 0; i < N; i++) {
		ll  k = P[i].first;
		int r = P[i].second;
    // x: 左端に配置した人数
		for(int x = 0; x <= i; x++) {
      // 右端に配置するときの位置
			int y = i - x;

      // なるべく左端に置く
			dp[x+1][y] = max(dp[x+1][y], dp[x][y] + abs(r-(x)) * k);

      // なるべく右端に置く
			dp[x][y+1] = max(dp[x][y+1], dp[x][y] + abs(r-(N-1-y)) * k);
		}
	}

	ll ret = -1LL<<60;
	for(int x = 0; x < N+1; x++) {
    ret = max(ret, dp[x][N-x]);
  }

	cout << ret << endl;
  return 0;	
}