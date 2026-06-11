#include <bits/stdc++.h>

using namespace std;

int main() {
	
	int N; cin >> N;
	pair<int, int> t[N]; // t for Task
	// cin >> t[0].second >> t[0].first; // {deadline, time}

	for (int i = 0; i < N; i++) {
		cin >> t[i].second >> t[i].first; // We put deadline into pair.first so that we can sort by it
	}
	sort(t, t+N); // Sort by deadline

	int sum = 0;
	int possible = true;
	for (int i = 0; i < N; i++) {
		sum += t[i].second;
		if (t[i].first < sum) possible = false;
		// cout << t[i].first << ' ' << sum << endl;
	}
	cout << (possible ? "Yes" : "No"); // Look at this one-line conditional
	return 0;
}