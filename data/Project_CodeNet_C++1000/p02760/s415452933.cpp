#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
#include<cmath>
#include<math.h>
#include<limits>
#include<list>
#include <stdio.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(int i = 0;i < (n); ++i)
#pragma GCC optimize("Ofast")



int main() {
	vector<vector<int>>a(3, vector<int>(3));
	rep(i, 3) {
		rep(j, 3)cin >> a[i][j];
	}
	int n;
	cin >> n;
	vector<int>b(n);
	rep(i, n)cin >> b[i];
	vector<vector<bool>>chack(3, vector<bool>(3,false));
	rep(i, n) {
		rep(j, 3) {
			rep(k, 3) {
				if (b[i] == a[j][k]) {
					chack[j][k] = true;
				}
			}
		}
	}
	rep(i, 3) {
		if (chack[i][0] ==true && chack[i][1] ==true&& chack[i][2] == true) {
			cout << "Yes" << endl;
			return 0;
		}
		if (chack[0][i] ==true&& chack[1][i] ==true&& chack[2][i] == true) {
			cout << "Yes" << endl;
			return 0;
		}
	}
	if (chack[0][0] ==true&& chack[1][1] ==true&& chack[2][2]==true) {
		cout << "Yes" << endl;
		return 0;
	}
	if (chack[0][2] ==true&& chack[1][1] ==true&& chack[2][0] == true) {
		cout << "Yes" << endl;
		return 0;
	}
	cout << "No" << endl;

	return 0;
}