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
	int n, m,x;

	cin >> n >> m >> x;

	vector<vector<int> > arr(n, vector<int>(m+1));

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m + 1; j++) {
			cin >> arr[i][j];
		}
	}

	int min = 100;
	int min1 = 0;
	for (int i = 0; i < n; i++) {
		min = min + arr[i][0];
		min1 = min;
	}
	for (int i = 0; i < (1 << n); i++) {

		//理解度を入れる配列
		vector<int> rikai(m);
		
		int count = 0;

		for (int h = 0; h < n; h++) {

				if (i & (1 << h)) {
					//金額を足す
					count = count+arr[h][0];
					//理解度の配列を作って入れる
					for (int k = 1; k < m + 1; k++) {
						rikai[k - 1] = rikai[k - 1] +arr[h][k] ;
					}
				}

		}

		//理解度が条件を満たすか、かつ、最小なら更新
		for (int i = 0; i < m; i++) {
			if (rikai[i] < x) {
				break;
			}
			if (i == m - 1 && count < min)min = count;
		}

	}
	
	if (min == min1)cout << -1 << endl;
	else cout << min << endl;

	return 0;
}