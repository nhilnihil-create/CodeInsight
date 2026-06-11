#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

int main() {
	int n, m;
	cin >> n >> m;
	vector<int> a(n);
	float total = 0;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
		total += a[i];
	}
	total /= 4 * m;
	int count = 0; 
	for (int i = 0; i < n; i++) {
		if (a[i] >= total) count++;
	}
	if (count >= m) cout << "Yes" << endl;
	else cout << "No" << endl;
	return 0;
}