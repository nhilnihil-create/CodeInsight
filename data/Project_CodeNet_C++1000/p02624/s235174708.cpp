#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

int main() {
	int n;
	cin >> n;
	vector<int> v(n + 1);
	for (int i = 1; i <= n; i++) {
		for (int j = i; j <= n; j += i) {
			v[j]++;
		}
	}
	long long ans = 0;
	for (int i = i; i <= n; i++) {
		ans += (long long) i * v[i];
	}
	cout << ans << endl;
}