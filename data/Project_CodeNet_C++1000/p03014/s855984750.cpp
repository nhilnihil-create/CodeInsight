#include <bits/stdc++.h>
#include <string>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define repi(i, a, b) for (int i = (int)(a); i < (int)(b); i++)
#define ll long long

int main() {
	int h,w;
	//入力
	cin >> h >> w;
	vector<string> s(h+1);
	rep(i, w) s[h] += '#';
	vector<vector<int>> g(h,vector<int>(w));
	//読み込み＆横列カウント
	rep(i, h) {
		string s1;
		cin >> s1;
		s[i] = s1;
		int j = 0;
		for (;j < s1.size();++j) {
			int cnt = 0;
			if (s1[j] == '.') {
				while (s1[j + cnt] == '.') {
					++cnt;
				}
				rep(k, cnt)	g[i][j+k] = cnt;
			}
			j += cnt;
		}
	}
	//縦列カウント加算
	rep(i, w) {
		int j = 0;
		for (;j < h;++j) {
			int cnt = 0;
			if (s[j][i] == '.') {
				while (s[j+cnt][i] == '.') {
					++cnt;
				}
				rep(k, cnt) g[j + k][i] += cnt-1;
			}
			j += cnt;
		}
	}
	//ansを求める
	int ans = 0;
	rep(i, h) {
		rep(j, w) {
			ans = max(ans, g[i][j]);
		}
	}

	std::cout << ans << endl;
}
