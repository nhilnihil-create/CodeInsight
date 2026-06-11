#include "bits/stdc++.h"

using namespace std;



int main() {
	int K;
	cin >> K;
	priority_queue<long long, vector<long long>, greater<long long> > q;
	q.push(1);
	q.push(2);
	q.push(3);
	q.push(4);
	q.push(5);
	q.push(6);
	q.push(7);
	q.push(8);
	q.push(9);
	int count = 0;
	while (!q.empty()) {
		count++;
		long long x = q.top();
		if (K == count) {
			cout << x << endl;
			return 0;
		}
		q.pop();
		for (int l = x % 10 -1; l <= x % 10 +1 ; ++l) {
			if (l >= 0&&l<=9) {
				q.push(10 * x + l);
			}
		}
	}
	return 0;
}