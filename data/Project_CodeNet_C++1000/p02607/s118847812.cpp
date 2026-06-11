#include<iostream>

using namespace std;

int main() {
	int n;
	cin >> n;
	int* a = new int[n];
	for (int i = 0;i < n;i++) {
		cin >> a[i];
	}
	int scoa = 0;
	for (int i = 0;i < n;i += 2) {
		if (a[i] % 2 == 1) {
			scoa++;
		}
	}
	cout << scoa << endl;
}