#include<iostream>
#include<algorithm>
using namespace std;
int main() {

	long long int n, m, v, p;
	cin >> n >> m >> v >> p;
	long long int a[100000];

	int i;
	for (i = 0; i < n; i++) {
		cin >> a[i];
	}
	sort(a, a + n);
	long long int counter = 0;
	int left = -1, right = n - 1, mid, dis = right - left;
	if (v <= p) {

		counter = p - 1;
		for (i = p; i <= n; i++) {
			if (a[n - i] + m >= a[n - p]) {
				counter++;
			}
		}

		cout << counter << endl;
		return 0;
	}
	else {


		while (dis > 1) {
			dis = right - left;
			mid = left + (int)((dis - (dis % 2)) / 2);
			counter = 0;
			if (a[mid] + m < a[n - p]) {
				left = mid;
			}
			else {
				for (i = 0; i < n; i++) {

					if (i <= mid) {
						counter = counter + m;
					}
					else if (i > n - p) {
						counter = counter + m;
					}
					else {
						counter = counter + a[mid] + m - a[i];
					}
				}
				if (counter < m * v) {
					left = mid;
				}
				else {
					right = mid;
				}
			}
		}
		cout << n - left - 1 << endl;
		return 0;
	}

	

}