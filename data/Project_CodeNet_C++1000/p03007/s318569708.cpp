#include <iostream>
#include <map>
#include <vector>
#include <algorithm>
using namespace std;

int N, A[100009], ret;
vector<pair<int, int>> ans;

int main() {
	cin >> N;
	for (int i = 0; i < N; i++) cin >> A[i];
	sort(A, A + N);
	reverse(A, A + N);

	if (A[0] < 0) {
		int v = A[0];
		for (int i = 0; i < N - 1; i++) {
			int p1 = i, p2 = i + 1;
			ans.push_back(make_pair(v, A[p2]));
			v = v - A[p2];
		}
		ret = v;
	}
	else if (A[N - 1] >= 0) {
		int v = A[N - 1];
		for (int i = 0; i < N - 2; i++) {
			ans.push_back(make_pair(v, A[i]));
			v = v - A[i];
		}
		ans.push_back(make_pair(A[N - 2], v));
		v = A[N - 2] - v;
		ret = v;
	}
	else {
		int a1 = 0, a2 = 0;
		for (int i = 0; i < N; i++) { if (A[i] >= 0) a1++; else a2++; }

		int v = A[N - 1];
		for (int i = 0; i < a1 - 1; i++) {
			ans.push_back(make_pair(v, A[i]));
			v = v - A[i];
		}
		ans.push_back(make_pair(A[a1 - 1], v));
		v = A[a1 - 1] - v;
		for (int i = a1; i < a1 + a2 - 1; i++) {
			ans.push_back(make_pair(v, A[i]));
			v = v - A[i];
		}
		ret = v;
	}
	cout << ret << endl;
	for (int i = 0; i < ans.size(); i++) cout << ans[i].first << " " << ans[i].second << endl;
	return 0;
}