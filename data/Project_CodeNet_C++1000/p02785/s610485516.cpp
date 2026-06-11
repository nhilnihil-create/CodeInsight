#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int main() {
	long long n, k;
	cin >> n >> k;
	vector<int> a(n);
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	long long num = 0;
	sort(a.begin(), a.end());
	for (int i = 0; i < n - k ; i++) {
		num += a[i];
	}
	cout << num;
	
}