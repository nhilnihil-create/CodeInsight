#include <bits/stdc++.h>
using namespace std;

#define MAX 100000

int main() {
	int N;
	vector<pair<int, int>> R;
	int ans = 0;
	cin >> N;
	for (int i = 0; i < N; i++) {
		int x, l;
		cin >> x >> l;
		R.push_back(make_pair(x + l, x - l));
	}
    sort(R.begin(), R.end());
    int r = R[0].first;
    ans++;
    for (int i = 1; i < N; i++) {
        if (R[i].second >= r) {
            ans++;
            r = max(r, R[i].first);
        }
    }
	cout << ans << endl;
	return 0;
}
