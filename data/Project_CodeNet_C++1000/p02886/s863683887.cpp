#include <iostream>
using namespace std;

int a[194];

int main() {
	int n;
	cin >> n;
	for(int i = 1; i <= n; ++i)
		cin >> a[i];
	int sum = 0;
	for(int i = 1; i <= n; ++i) {
		for(int j = i + 1; j <= n; ++j) {
			sum += a[i] * a[j];
		}
	}
	cout << sum;
}
