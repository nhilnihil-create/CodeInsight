#include <iostream>
#include <algorithm>
using namespace std;

int n, a[1000];

int main(){
	int mi;
	while (cin >> n && n != 0) {
		for (int i = 0; i < n; i++) {
			cin >> a[i];
		}
		sort(a, a + n);
		mi = a[1] - a[0];
		for (int i = 1; i < n - 1; i++) {
			if (a[i + 1] - a[i] < mi) {
				mi = a[i + 1] - a[i];
			}
		}
		cout << mi << endl;
	}

	return 0;
}