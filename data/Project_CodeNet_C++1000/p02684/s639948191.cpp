#include <iostream>
#include <vector>
using namespace std;

int main() {
	long long n, k;
	cin >> n >> k;
	vector<int> A(n);
	for (int i = 0; i < n; i++) {
		cin >> A[i];
		A[i]--;
	}
	int a, b;
	vector<int> order(n, -1);
	for (int i = 0, x = 0; ; i++) {
		if (order[x] != -1) {
			a = order[x];
			b = i;
			break;
		}
		order[x] = i;
		x = A[x];
	}
	const int t = b - a;

	int l = 0, x = 0;
	for (; l < a && l < k; l++) {
		x = A[x];
	}
	k -= l;

	k %= t;
	for (int i = 0; i < k; i++) {
		x = A[x];
	}
	cout << x+1 << endl;
	return 0;
}