#include<iostream>
using namespace std;
int main() {
	int N;
	int x=0;
	cin >> N;
	int a[100];
	for (int s = 0; s < N; s++) {
		cin >> a[s];
	}
	for (int i = 1; i <= N; i++) {
		if (a[i-1] % 2 != 0 && i % 2 != 0) {
				x++;
		}
	}
	cout << x;
	return 0;
}
