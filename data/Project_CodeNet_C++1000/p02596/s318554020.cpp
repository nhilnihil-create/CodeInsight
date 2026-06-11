#include<bits/stdc++.h>
using namespace std;

#define ll long long

int main() {
	int k;
	cin >> k;

	int first = 7;
	for (int i = 1; i <= 1e7 ; i++) {
		if (first % k == 0) {
			cout << i << endl;
			return 0;
		}
		first = ((first * 10) + 7 ) % k ;
	}
	cout << -1 << endl;
}