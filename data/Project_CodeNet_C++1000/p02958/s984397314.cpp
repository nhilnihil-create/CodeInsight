#include<iostream>
#include<vector>
#include<algorithm>


using namespace std;

int main() {
	int n;
	cin >> n;
	vector<int> a(n+1);
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	int ans = 0;
	for (int i = 1; i <= n; i++) {
		if (a[i] != i) {
			ans++;
		}
	}
	if (ans > 2) {
		cout << "NO";
	}
	else {
		cout << "YES";
	}
}