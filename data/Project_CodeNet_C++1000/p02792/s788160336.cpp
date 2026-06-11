#include <bits/stdc++.h>
#define rep(i,n) for(int i=0;i<(n);++i)
#define rrep(i,n) for(int i=1;i<(n);++i)
#define all(a) (a).begin(),(a).end()
#define rall(a) (a).rbegin(),(a).rend()
#define maxs(a, b) a = max(a, b)
#define mins(a, b) a = min(a, b)
using namespace std;
typedef long long ll;
typedef pair<int, int> P;
const ll linf = (1ll << 61);
const int inf = 1001001001;
const int mod = 1000000007;

const int dx[] = { 0,1 };
const int dy[] = { 1,0 };
char mp[10][10];
bool used[10][10];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n;
	cin >> n;
	vector<vector<int>> cnt(10, vector<int>(10));
	for (int i = 1; i <= n; ++i) {
		int a = i % 10;
		int b = i;
		while (b >= 10) b /= 10;
		cnt[a][b]++;
	}
	int ans = 0;
	rep(i, 10)rep(j, 10) ans += cnt[i][j] * cnt[j][i];
	printf("%d\n", ans);
	return 0;
}
