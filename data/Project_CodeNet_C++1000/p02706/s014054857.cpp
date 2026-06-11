#include <iostream>
using namespace std;

int main() {
	int n;
	cin >> n;
	int m;
	cin >> m;
	long long tot = 0;
	while(m--) {
		int x;
		cin >> x;
		tot += x;
	}
	cout << (n - tot < 0 ? -1 : n - tot);
}
