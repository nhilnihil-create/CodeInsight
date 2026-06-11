#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
vector<int> find_divisors(int x) {
	vector<int> d;
	for (int i = 1; i * i <= x; ++i) {
		if (x % i == 0) {
			d.push_back(i);
			if (i * i != x) {
				d.push_back(x / i);
			}
		}
	}
	sort(d.begin(), d.end());
	return d;
}
int main() {
	int N, K;
	cin >> N >> K;
	vector<int> A(N);
	int sum = 0;
	for (int i = 0; i < N; ++i) {
		cin >> A[i];
		sum += A[i];
	}
	vector<int> d = find_divisors(sum);
	int ans = 1;
	for (int i : d) {
		vector<int> lv(N), rv(N);
		for (int j = 0; j < N; ++j) {
			lv[j] = A[j] / i * i;
			rv[j] = lv[j] + i;
		}
		vector<bool> sel(N);
		int gsum = 0, cost = 0;
		for (int j = 0; j < N; ++j) {
			if (A[j] - lv[j] <= rv[j] - A[j]) {
				gsum += lv[j];
				cost += A[j] - lv[j];
			}
			else {
				gsum += rv[j];
				cost += rv[j] - A[j];
				sel[j] = true;
			}
		}
		if (gsum <= sum) {
			vector<int> turn;
			for (int j = 0; j < N; ++j) {
				if (!sel[j]) {
					turn.push_back((rv[j] - A[j]) - (A[j] - lv[j]));
				}
			}
			sort(turn.begin(), turn.end());
			for (int j = 0; gsum < sum; ++j) {
				cost += turn[j];
				gsum += i;
			}
			if (cost <= 2 * K) {
				ans = i;
			}
		}
		else {
			vector<int> turn;
			for (int j = 0; j < N; ++j) {
				if (sel[j]) {
					turn.push_back(-((rv[j] - A[j]) - (A[j] - lv[j])));
				}
			}
			sort(turn.begin(), turn.end());
			for (int j = 0; gsum > sum; ++j) {
				cost += turn[j];
				gsum -= i;
			}
			if (cost <= 2 * K) {
				ans = i;
			}
		}
	}
	cout << ans << endl;
	return 0;
}