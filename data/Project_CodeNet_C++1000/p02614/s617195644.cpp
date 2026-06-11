#include <bits/stdc++.h>
using namespace std;
string s[7];
int R, C, k;
bool func(int x, int y) {
	int cnt = 0;
	for (int i = 0; i < R; ++i) {
		for (int j = 0; j < C; ++j) {
			if(x&(1 << i) || y &(1 << j))
				continue;
			if(s[i][j] == '#')
				++cnt;		
		}
	}
	if(cnt == k)
		return true;
	return false;
}

int main() {
	//freopen("input.txt", "r", stdin);
	cin >> R >> C >> k;
	for (int i = 0; i < R; ++i) {
		cin >> s[i];
	}
	int ans = 0;
	for (int i = 0; i < (1 << R); ++i) {
		for (int j = 0; j < (1 << C); ++j) {
			if(func(i, j))
				++ans;
		}
	}

	cout << ans << '\n';
	return 0;
}