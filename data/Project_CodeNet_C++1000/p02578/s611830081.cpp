#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main() {
	int n;
	cin >> n;
	vector<int> a(n);
	for (int i = 0; i < n; i++) cin >> a[i];

	long long int h = 0;
	long long int ans = 0;
	for (int i = 0; i < n; i++) {
		if (h > a[i]) {
			ans+= h - a[i] ;
		}
		else h = a[i];
	}

	cout << ans << endl;
	return 0;
}
