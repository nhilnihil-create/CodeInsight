#include <iostream>
#include <stdio.h>

#include <vector>
#include <cctype>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <string>
#include <map>
#include <climits>
#include <iomanip>

using namespace std;

int main() {
	int n, m,p;
	
	cin >> n >> m;

	vector<int> h(n+1);
	
	for (int i = 0; i < n; i++)cin >> h[i+1];

	vector<vector<int> > arr(m, vector<int>(2));

	for (int i = 0; i < m; i++) {
		for (int j = 0; j < 2; j++) {
			cin >> arr[i][j];
		}
	}

	vector<int> point(n+1);

	//arr[i][j]の関連を判定
	//小さいほう基準で選ぶ
	//高さを比較して、一致するものがあれば、フラグを1にする

	for (int i = 0; i < m; i++) {
		if (h[arr[i][0]]>h[arr[i][1]]) {
			point[arr[i][1]]++;
		}

		if (h[arr[i][0]] < h[arr[i][1]]) {
			point[arr[i][0]]++;
		}

		if (h[arr[i][0]] == h[arr[i][1]]) {
			point[arr[i][0]]++;
			point[arr[i][1]]++;
		}
	}

	int ans = 0;
	for (int i = 1; i <= n; i++) {
		if (point[i] == 0)ans++;
	}

	cout << ans << endl;

	return 0;
}
