#include <bits/stdc++.h>
using namespace std;

int main() {
	int N;
	cin >> N;
	vector<int> A(N), ded(1e6+5), done(1e6+5);
	for (int& e : A) cin >> e;
	sort(A.begin(), A.end());
	int ans = 0, dups = 0;
	for (int a : A) {
		if (!ded[a]) ++ans;
		if (done[a]) {
			if (done[a] == 1) {
				done[a] = 2;
				++dups;
			}
			continue;
		}
		done[a] = ded[a] ? 2 : 1;
		int mult = a;
		// cout << a << endl;
		while (mult <= 1e6) {
			ded[mult] = 1;
			mult += a;
		}
	}
	cout << ans-dups << endl;
}