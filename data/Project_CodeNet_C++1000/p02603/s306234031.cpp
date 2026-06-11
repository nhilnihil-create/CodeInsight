#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int n;
	cin >> n;
	long long money = 1000, stocks = 0;
	vector<int> a(n);
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	for (int i = 0; i < n - 1; i++) {
		money += stocks * a[i];
		stocks = 0;
		if (a[i] < a[i + 1]) {
			stocks = money/a[i];
			money -= stocks * a[i];
		}
	}
	money += stocks * a[n - 1];
	cout << money;
}
