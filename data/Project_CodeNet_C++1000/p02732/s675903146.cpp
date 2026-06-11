#include <iostream>
using namespace std;
const int MAX = 200000;

int main() {
	int n;
	cin >> n;
	int A[n];
	int bin[MAX+1] = {0};
	for (int i = 0; i < n; i++) {
		cin >> A[i];
		bin[A[i]]++;
	}
	long long s = 0;
	for (int i = 0; i <= MAX; i++) {
		s += (long long)bin[i] * (bin[i] - 1) / 2;
	}
	for (int i = 0; i < n; i++) {
		long long ans = s - (bin[A[i]] - 1);
		cout << ans << endl;
	}
}
