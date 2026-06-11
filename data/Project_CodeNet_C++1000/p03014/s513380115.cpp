#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;
typedef vector<vector<int>> Graph;
const int dx[4] = {1, 0, -1, 0};
const int dy[4] = {0, 1, 0, -1};
#define pi 3.14159265359
#define inf 2147483647
#define INF 9223372036854775807
#define mod 1000000007
#define mod2 998244353

int main() {
	int H, W; cin >> H >> W;
	vector<string> S(H);
	for(int i = 0; i < H; i++) cin >> S[i];
	vector<vector<int>> mapping(H, vector<int>(W));
	for(int i = 0; i < H; i++) {
		int start = 0, goal = 0;
		for(int j = 0; j < W; j++) {
			if(S[i][j] == '#') {
				for(int k = start; k < goal; k++) mapping[i][k] += goal - start;
				start = j + 1; goal = j + 1;
				continue;
			}
			goal++;
			if(j == W - 1) {
				for(int k = start; k < goal; k++) mapping[i][k] += goal - start;
			}
		}
	}
	for(int j = 0; j < W; j++) {
		int start = 0, goal = 0;
		for(int i = 0; i < H; i++) {
			if(S[i][j] == '#') {
				for(int k = start; k < goal; k++) mapping[k][j] += goal - start;
				start = i + 1; goal = i + 1;
				continue;
			}
			goal++;
			if(i == H - 1) {
				for(int k = start; k < goal; k++) mapping[k][j] += goal - start;
			}
		}
	}
	int ans = 0;
	for(int i = 0; i < H; i++) for(int j = 0; j < W; j++) ans = max(ans, mapping[i][j]);
	/*for(int i = 0; i < H; i++) {
		for(int j = 0; j < W; j++) {
			cout << mapping[i][j] << " ";
		}
		cout << endl;
	}*/
	ans--;
	cout << ans << endl;
	return 0;
}