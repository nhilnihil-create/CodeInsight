#include<iostream>
#include<vector>
#include<algorithm>
#include<functional>
#include<string>
using namespace std;
int main() {
	int n; cin >> n;
	for (int i = 0; i <= n; i++) {
		if ((i * 1.08) < n + 1 && (i * 1.08) >= n) {
			cout << i << endl;
			return 0;
		}
	}
	cout << ":(" << endl;
}