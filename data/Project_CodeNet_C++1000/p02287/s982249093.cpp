#include<iostream>
using namespace std;
int a[251];
int main(void) {
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	for (int i = 1; i <= n; i++) {
		int parent = i / 2;
		int left = i * 2;
		int right = i * 2 + 1;
		cout << "node " << i << ": key = " << a[i]<<", ";
		if (parent) {
			cout  << "parent key = " << a[parent] << ", ";
		}
		if (left <= n) {
			cout  << "left key = " << a[left] << ", ";
		}
		if (right <= n) {
			cout << "right key = " << a[right] << ", ";
		}
		cout << endl;
	}
}
