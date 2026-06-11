#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main() {
	int h, w, k;
	int ans=0,num=0;
	cin >> h >> w >> k;
	// 表入力
	vector<string> a(h);
	string aStr;
	rep(i, h) {
		cin >> a[i];
	}
	// 横の選び方 2^w
	// 1をビットシフトして2^wを再現
	rep(i, 1<<w) {
		// 横の選び方 2^h
		// 1をビットシフトして2^hを再現 
		rep(j, 1 << h) {
			num = 0;
			// 行・列を選択していく
			rep(is, w) {
				rep(js, h) {
					if (((i >> is) & 1) == 1) {
						if (((j >> js) & 1) == 1) {
							if (a.at(js).at(is) == '#') {
								num++;
							}
						}
					}
				}
			}
			if (num == k) {
				ans++;
			}
		}
	}
	cout << ans << endl;
	return 0;
}