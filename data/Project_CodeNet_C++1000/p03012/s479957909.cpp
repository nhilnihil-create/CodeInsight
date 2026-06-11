#include<iostream>
#include<vector>
using namespace std;
#define rep(i,n) for(int i=0;i<(n);++i)
using ll = long long;
using P = pair<int, int>;
#include<algorithm>
#include<math.h>
#include<map>
#include<queue>
#include<set>

int main() {
	int n;
	cin >> n;
	vector<int>w(n);
	int all(0);
	rep(i, n) {
		cin >> w[i];
		all += w[i];
	}
	//sort(w.begin(), w.end());
	int k = 105;
	//int sum(0);
	int ans(1e9);
	int sum(0);
	rep(i, n) {
		sum += w[i];
		int dist = abs(sum - (all - sum));
		ans = min(ans, dist);
	}
	cout << ans;
	return 0;
}