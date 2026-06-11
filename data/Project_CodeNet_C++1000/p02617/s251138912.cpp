#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main(){
	int n;
	cin >> n;
	ll topNum = 0;
	ll linNum = 0;
	ll ans = 0;
	// n-1行2列の行列
	vector<vector<int>> line(n-1, vector<int>(2));
	rep(i, n - 1) {
		rep(j, 2) {
			cin >> line.at(i).at(j);
		}
	}
	// 頂点の数をかぞえる
	rep(i, n) {
		topNum = topNum + ((ll)n - (ll)i)* ((ll)i + 1);
	}
	// 辺の数を数える
	rep(i, n - 1) {
		// u < vの時
		if (line.at(i).at(0) < line.at(i).at(1)) {
			linNum = linNum + (ll)(line.at(i).at(0)) * (ll)(n - (line.at(i).at(1)) + 1);
		}
		// u > vの時
		else {
			linNum = linNum + (ll)(line.at(i).at(1)) * (ll)(n - (line.at(i).at(0)) + 1);
		}
	}
	ans = topNum - linNum;
	cout << ans << endl;
	return 0;
}