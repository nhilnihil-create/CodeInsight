#include<iostream>
#include<vector>
using namespace std;
int main() {
	int n; cin >> n;
	vector<int> a(n);
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	long long sum = 0;
	for (int i = 1; i < n; i++) {
		if (a[i - 1] > a[i]) {
			sum += a[i - 1] - a[i];
			a[i] = a[i - 1];
		}
	}
	cout << sum << endl;
}