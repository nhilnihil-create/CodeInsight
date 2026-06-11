#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
#include <queue>
#include <time.h>
using namespace std;
typedef long long ll;

int main()
{
	int N; cin >> N;
	vector<pair<int, int>> R(N);
	for (int i = 0; i < N; ++i) {
		int x, l; cin >> x >> l;
		R[i] = make_pair(x - l, x + l);
	}
	auto cmpr = [](pair<int, int> a, pair<int, int> b) {
		if (a.second != b.second) return a.second < b.second;
		else return a.first < b.first;
	};
	sort(R.begin(), R.end(), cmpr);
	int ans = 0;
	int cur = 1 << 31; cur *= -1;
	for (int i = 0; i < N; ++i) {
		if (cur > R[i].first) continue;
		cur = R[i].second;
		++ans;
	}
	cout << ans << endl;
}
