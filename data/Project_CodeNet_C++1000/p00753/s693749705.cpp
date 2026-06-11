#include<iostream>
#include<vector>
#include<list>
#include<string>
#include<algorithm>
#include<map>
#include<cmath>
#include<set>
using namespace std;
bool a[2 * 123456 + 1];
int main() {
	fill(a, a + 2 * 123456 + 1, true);
	a[0] = false;
	a[1] = false;
	for (int i = 2; i <= 2 * 123456; i++) {
		if (a[i]) {
			int j = 2;
			while (i*j <= 2 * 123456) {
				a[i*j] = false;
				j++;
			}
		}
	}
	int n;
	while (cin >> n&&n != 0) {
		int sum = 0;
		for (int i = n + 1; i <= n * 2; i++) {
			if (a[i]) sum++;
		}
		cout << sum << endl;
	}
}