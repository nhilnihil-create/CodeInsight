#include<iostream>
using namespace std;

int main() {
	int n; cin >> n;
	int cnt = n / 1000 + (n % 1000 ? 1 : 0);
	cout << cnt * 1000 - n << endl;

	return 0;
}