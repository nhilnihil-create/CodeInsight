#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); i++)
using namespace std;
using ll = long long;
using P = pair<int, int>;
const int MAX = 1000;
const int INF = 1e9;
const int dx[] = {-1,0,1,0};
const int dy[] = {0,-1,0,1};
#define PI 3.14159265358979323846264338327950L
//setprecision(15)

int main() {
	vector<vector<int>> v(3, vector<int>(3));
	rep(i, 3) {
		rep(j, 3) {
			cin >> v.at(i).at(j);
		}
	}
	int N; cin >> N;
	rep(i, N) {
		int temp; cin >> temp;
		rep(j, 3) {
			rep(k, 3) {
				if (v.at(j).at(k) == temp) {
					v.at(j).at(k) = 0;
				}
			}
		}
	}
	rep(i, 3) {
		if (v.at(i).at(0) != 0) {
			continue;
		}
		if (v.at(i).at(1) == 0 && v.at(i).at(2) == 0) {
			goto BINGO;
		}
	}
	rep(i, 3) {
		if (v.at(0).at(i) != 0) {
			continue;
		}
		if (v.at(1).at(i) == 0 && v.at(2).at(i) == 0) {
			goto BINGO;
		}
	}
	if (v.at(0).at(0) == 0 && v.at(1).at(1) == 0 && v.at(2).at(2) == 0) {
		goto BINGO;
	}
	if (v.at(2).at(0) == 0 && v.at(1).at(1) == 0 && v.at(0).at(2) == 0) {
		goto BINGO;
	}
	cout << "No" << endl;
	return 0;
BINGO:
	cout << "Yes" << endl;
	return 0;
}