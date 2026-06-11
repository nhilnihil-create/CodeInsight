#include<iostream>
using namespace std;
int main() {
	int n, k;
	cin >> n >> k;
	int temp,sum=0;
	int a[1000];
	for (int s = 0; s < n; s++) {
		cin >> a[s];
	}
	for (int i = 0; i <= n; i++) {
		for (int j = i + 1; j < n; j++) {
			if (a[j] < a[i]) {
				temp = a[i];
				a[i] = a[j];
				a[j] = temp;
			}
		}
	}
	for (int i = 0; i < k; i++) {
		sum += a[i];
	}
	cout << sum;
	return 0;
}
