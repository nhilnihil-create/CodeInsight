#include <algorithm>
#include <iostream>
#include <vector>
#include <map>
#include <queue>
#include <string>
#include <cmath>
using namespace std;

#undef INT_MIN
#undef INT_MAX
#define INT_MIN -2147483648
#define INT_MAX 2147483647

void dfs(int count, vector<int> &vec, int j, vector<int> s, vector<vector<int>> &ret) {
	if (count == s.size()) {
		ret.push_back(s);
		return;
	}

	for (int i = j; i < vec.size(); ++i) {
		vector<int> buf;
		buf = s;
		buf.push_back(vec[i]);
		dfs(count, vec, i, buf, ret);
	}

}

int main() {
	int N, M, Q;
	cin >> N >> M >> Q;
	vector<tuple<int, int, int, int>> vec(Q);
	for (int i = 0; i < Q; ++i) {
		int a, b, c, d;
		cin >> a >> b >> c >> d;
		vec[i] = make_tuple(a, b, c, d);
	}

	vector<int> A;
	for (int i = 1; i <= M; ++i) {
		A.push_back(i);
	}

	vector<int> s;
	vector<vector<int>> ret;
	dfs(N, A, 0, s, ret);

	int maxScore = INT_MIN;
	for (size_t t = 0; t < ret.size(); ++t) {
		int score = 0;
		for (int i = 0; i < Q; ++i) {
			int a = get<0>(vec[i]), b = get<1>(vec[i]), c = get<2>(vec[i]), d = get<3>(vec[i]);
			int Aa = (ret[t][a - 1] - 0x30);
			int Ab = (ret[t][b - 1] - 0x30);
			if (Ab - Aa == c) {
				score += d;
			}
		}
		maxScore = max(maxScore, score);
	}

	cout << maxScore << endl;
	return 0;
}