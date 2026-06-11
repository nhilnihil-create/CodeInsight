#include <iostream>
#include <vector>
using namespace std;

vector<pair<int, int>> ans;

void solve(int N) {
	if (N == 1) {
		cout << "No" << endl;
		return;
	}
	if (N == 2) {
		cout << "No" << endl;
		return;
	}
	if (N >= 3) {
		int P = (N - 3) / 4; P = P * 4 + 3;
		for (int i = 1; i <= P * 2 - 1; i++) {
			int v1 = i, v2 = i + 1;
			if (v1 > P) { v1 -= P; v1 += N; }
			if (v2 > P) { v2 -= P; v2 += N; }
			ans.push_back(make_pair(v1, v2));
		}

		if (N % 4 == 0) {
			bool flag = false;
			for (int i = 0; i < P; i++) {
				int Q = (i^N);
				int v1 = i + 1, v2 = Q;
				if (v1 < v2 && v2 <= P) {
					ans.push_back(make_pair(v1, N)); ans.push_back(make_pair(v2, 2 * N));
					flag = true;
					break;
				}
			}
			if (flag == false) {
				cout << "No" << endl;
				return;
			}
		}
		if (N % 4 == 1) {
			ans.push_back(make_pair(N - 1, N));
			ans.push_back(make_pair(N, N + 1));
			ans.push_back(make_pair(N + 1, 2 * N - 1));
			ans.push_back(make_pair(2 * N - 1, 2 * N));
		}
		if (N % 4 == 2) {
			ans.push_back(make_pair(N - 2, N - 1));
			ans.push_back(make_pair(N - 1, N + 1));
			ans.push_back(make_pair(N + 1, 2 * N - 2));
			ans.push_back(make_pair(2 * N - 2, 2 * N - 1));
			ans.push_back(make_pair(2 * N - 2, 2 * N));
			ans.push_back(make_pair(3, N));
		}
		cout << "Yes" << endl;
		for (int i = 0; i < ans.size(); i++) {
			cout << ans[i].first << " " << ans[i].second << endl;
		}
	}
}

int main() {
	int N;
	cin >> N;
	solve(N);
	return 0;
}