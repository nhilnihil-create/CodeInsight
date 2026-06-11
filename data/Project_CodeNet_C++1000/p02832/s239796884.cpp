#include <iostream>
#include <vector>
using namespace std;
int main() {
	int n;
	cin >> n;
	vector<int> arr;
	for (int i = 0; i < n; i++) {
		int a;
		cin >> a;
		arr.push_back(a);
	}
	if (n == 1) {
		cout << 0;
		return 0;
	}int i = 0;
	int j = 1;
	int ans = 0;
	while (i < arr.size()) {
		if (arr.at(i) != j) {
			arr.erase(arr.begin() + i);
			ans++;
		}
		else {
			i++;
			j++;
		}
	}if (n == ans) {
		ans = -1;
	}
	cout << ans;
	return 0;
}