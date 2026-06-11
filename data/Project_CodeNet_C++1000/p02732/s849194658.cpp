#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
#include <algorithm>
#include <math.h>
using namespace std;
#define INF (1e9)
#define PI (acos(-1))

int main() {
	int n;
	cin >> n;
	vector<int> a(n);
	vector<long long> table(n, 0);
	for (int i = 0; i < n; i++) {
		cin >> a[i];
		a[i]--;
		table[a[i]]++;
	}
	long long sum = 0, ans;

	for (int i = 0; i < n; i++) {
		if (table[i] > 1) {
			long long x = table[i];
			sum += x*(x-1)/2;
		}
	}

	for (int i = 0; i < n; i++) {
		ans = sum - (table[a[i]]-1);
		cout << ans << endl;
	}
	return 0;
}