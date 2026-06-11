#include<iostream>
#include<algorithm>
#include<stack>
#include<queue>
#include<cmath>
#include<functional>
#include<string>
#include<vector>
#include<cstring>
#include<utility>
#include<set>
#include<map>

#define ll long long
#define ull unsigned long long
#define MOD 1000000007
#define MAX 2e9
#define pii pair<int, int>
#define pll pair<ll, ll>
#define all(v) v.begin(), v.end()
const double PI = acos(-1);

using namespace std;

int main(void) {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	//	freopen("input.txt", "r", stdin);
	
	int H, W, K; cin >> H >> W >> K;
	vector<string> v(H);
	int ans = 0;
	for (int i = 0; i < H; i++) cin >> v[i];
	for (int r = 0; r < (1 << H); r++) {
		for (int c = 0; c < (1 << W); c++) {
			int cnt = 0;
			for (int i = 0; i < H; i++) {
				for (int j = 0; j < W; j++) {
					if (((r >> i) & 1) == 0 && ((c >> j) & 1) == 0 && v[i][j] == '#') cnt++;
				}
			}
			if (cnt == K) ans++;
		}
	}
	cout << ans;
}
