#include <iostream>
#include <vector>

using namespace std;
int main() {
	int h, n;
	cin >> h >> n;

	vector<int> a(n);
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}

	int sum = 0;
	for (int i = 0; i < n; i++) {
		sum += a[i];
	}
	if (h <= sum)cout << "Yes" << endl;
	else cout << "No" << endl;
	return 0;
}