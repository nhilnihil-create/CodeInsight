#include<iostream>
using namespace std;

int partition(int a[], int p, int r);

int main() {
	int i, n, key, a[100000];
	cin >> n;
	for (i = 0; i < n; i++) cin >> a[i];
	key = partition(a, 0, n - 1);
	for (i = 0; i < n; i++) {
		if (i == key)cout << "[" << a[i] << "]";
		else cout << a[i];
		if (i != n - 1)cout << " ";
	}
	cout << endl;
	return 0;
}

int partition(int a[], int p, int r) {
	int i, j, x;
	x = a[r];
	i = p - 1;
	for (j = p; j < r; j++) {
		if (a[j] <= x) {
			i++;
			swap(a[i], a[j]);
		}
	}
	swap(a[i + 1], a[r]);
	return i + 1;
}