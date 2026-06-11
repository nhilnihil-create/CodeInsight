#include<iostream>
#include<algorithm>
using namespace std;
int a[200000], L[200000], R[200000];
int main() {
	//abc166_e
	int n;

	cin >> n;
	int i;
	for (i = 0; i < n; i++) {
		cin >> a[i];
		L[i] = i - a[i];
		R[i] = i + a[i];
	}
	//i > j
	//i - j = ai + aj
	//i - ai = j + aj
	int left, right, mid, upper, downer;
	sort(R, R + n);
	long long int counter = 0;
	for (i = 0; i < n; i++) {
		left = -1;
		right = n;
		while (right - left > 1) {
			mid = (left + right) / 2;

			if (L[i] > R[mid]) {
				left = mid;
			}
			else {
				right = mid;
			}
		}
		downer = left;
		left = -1;
		right = n;
		while (right - left > 1) {
			mid = (left + right) / 2;
			if (L[i] >= R[mid]) {
				left = mid;
			}
			else {
				right = mid;
			}
		}
		upper = right;
		counter = counter + upper - downer - 1;

	}
	cout << counter << endl;
	return 0;

}