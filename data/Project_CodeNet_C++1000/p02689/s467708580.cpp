#include<algorithm>
#include<iostream>
#include<vector>
#include<string>
#include<queue>
#include<stack>
#include<cmath>
#include<list>
#include<set>
#include<map>

using namespace std;
long long MOD = 1000000007LL;
const double PI = 3.14159265358979323846;
#undef INT_MIN
#undef INT_MAX
#define INT_MIN -2147483648
#define INT_MAX 2147483647
#define endl "\n"

int main() {
	int N, M;
	cin >> N >> M;
	vector<long long> H(N);
	for (int i = 0; i < N; ++i) {
		cin >> H[i];
	}

	vector<vector<int>> vec;
	vec.resize(N);
	for (int i = 0; i < M; ++i) {
		int a, b;
		cin >> a >> b;
		vec[a - 1].push_back(b - 1);
		vec[b - 1].push_back(a - 1);
	}

	int bestPeaks = 0;

	for (int i = 0; i < vec.size(); ++i) {
		int count = 0;
		for (int j = 0; j < vec[i].size(); ++j) {
			if (H[i] <= H[vec[i][j]]) {
				++count;
				break;
			}
		}
		if (count == 0) {
			bestPeaks++;
		}
	}

	cout << bestPeaks << endl;
	return 0;
}


