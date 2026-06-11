#include<vector>
#include<iostream>
#include<algorithm>

using namespace std;

int main() {
	int h, n;
	cin >> h >> n;
	vector<int> a(n);
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	long long sum = 0;
	for (int i = 0; i < n; i++) {
		sum += a[i];
	}
	if (sum >= h) {
		cout << "Yes";
	}
	else {
		cout << "No";
	}
}