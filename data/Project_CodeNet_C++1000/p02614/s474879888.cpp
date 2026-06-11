#include<iostream>
#include<string>
#include<vector>
using namespace std;
int main() {

	int H, W, K;
	cin >> H >> W >> K;
	vector<string> s(H);
	for (int i = 0; i < H; i++) {
		cin >> s[i];
	}

	int ans = 0;
	for (int is = 0; is < 1 << H; is++) {
		for (int js = 0; js < 1 << W; js++) {
			int cnt = 0;
			for (int i = 0; i < H; i++) {
				for (int j = 0; j < W; j++) {
					if ((is >> i & 1) || (js >> j & 1)) continue;
					else if (s[i][j] == '#') cnt++;
				}
			}
			if (cnt == K) ans++;
		}
	}

	cout << ans << endl;

	return 0;
}