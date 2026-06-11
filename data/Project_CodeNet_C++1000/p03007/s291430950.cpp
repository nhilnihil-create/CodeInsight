#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
using namespace std;

int main() {
	int N;
	cin >> N;
	vector<int> A(N);
	for (int i = 0; i < N; i++) cin >> A[i];
	sort(A.begin(), A.end());
	int ans = A[N - 1] - A[0];
	for (int i = 1; i < N - 1; i++) ans += abs(A[i]);
	cout << ans << endl;
	int n = 0, m = N - 1;
	int MIN = A[n], MAX = A[m];
	for (int i = 0; i < N - 2; i++) {
		if (A[n + 1] < 0) {
			cout << MAX << " " << MIN << endl;
			MAX = MAX - MIN;
			n++;
			MIN = A[n];
		}
		else {
			cout << MIN << " " << MAX << endl;
			MIN = MIN - MAX;
			m--;
			MAX = A[m];
		}
	}
	cout << MAX << " " << MIN << endl;
}
