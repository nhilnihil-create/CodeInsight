#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

int main() {
	int k, n;
	cin >> k >> n;
	vector<int> a(n);
	for (int i = 0; i < n; i++) cin >> a[i];
	vector<int> dist(n);
	int longest_dist = 0;
	int ignore;
	for (int i = 0; i < n - 1; i++) {
		dist[i] = a[i + 1] - a[i];
		if (longest_dist < dist[i]) {
			longest_dist = dist[i];
			ignore = i;
		}
	}
	dist[n - 1] = k - a[n - 1] + a[0];
	if (longest_dist < dist[n - 1]) {
		longest_dist = dist[n - 1];
		ignore = n - 1;
	}
	int sum_dist = 0;
	for (int i = 0; i < n; i++) {
		if (ignore == i) continue;
		sum_dist += dist[i];
	}
	cout << sum_dist << endl;
	return 0;
}