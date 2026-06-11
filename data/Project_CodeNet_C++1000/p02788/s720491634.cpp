#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

//see answer
int main() {
	int N;
	long long D, A;
	cin >> N >> D >> A;
	vector<pair<long long, long long>> XH(N);
	for (int i = 0; i < N; i++) cin >> XH[i].first >> XH[i].second;
	sort(XH.begin(), XH.end());

	vector<int> End(N, N);
	int l = 0;
	for (int i = 0; i < N; i++) {
		long long x = XH[i].first;
		while (XH[l].first + 2 * D < x) {
			End[l] = i;
			l++;
		}
	}

	vector<long long> Bombs(N, 0);
	long long bomb = 0, ans = 0;
	for (int i = 0; i < N; i++) {
		bomb += Bombs[i];
		long long h = XH[i].second;
		h -= bomb;
		if (h > 0) {
			long long n = (h + A - 1) / A;
			ans += n;
			bomb += n * A;
			if (End[i] < N) Bombs[End[i]] -= n * A;
		}
	}
	cout << ans << endl;

}