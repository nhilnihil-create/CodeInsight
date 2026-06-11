#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdlib>
using namespace std;

typedef long long LL;

void chmin(LL &x, LL y){ x = min(x, y); }

int main(){
	const LL INF = 1LL << 60;
	ios::sync_with_stdio(false);

	int n, k;
	cin >> n >> k;
	vector<LL> hs(n + 1);
	for(int i = 1; i <= n; ++i){
		cin >> hs[i];
	}

	vector<vector<LL>> dp1(k + 1, vector<LL>(n + 2, INF)), dp2;
	dp1[0][0] = 0;
	for(int x = 1; x <= n; ++x){
		dp2.assign(k + 1, vector<LL>(n + 2, INF));
		for(int y = 0; y <= k; ++y)
		for(int z = 0; z < x; ++z){
			if(y < k){ chmin(dp2[y + 1][z], dp1[y][z]); }
			chmin(dp2[y][x], dp1[y][z] + max(hs[x] - hs[z], 0LL));
		}
		dp1.swap(dp2);
	}
	LL ans = INF;
	for(const auto &v : dp1){
		chmin(ans, *min_element(v.begin(), v.end()));
	}
	cout << ans << '\n';
}
