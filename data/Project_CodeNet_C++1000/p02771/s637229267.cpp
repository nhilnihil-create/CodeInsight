#include<bits/stdc++.h>
using namespace std;
int main() {
	int a, b, c, countOne = 0, countTwo = 0;
	cin >> a >> b >> c;

	if(a == b && b == c) {
		cout << "No\n";
		return 0;
	}

	if(a == b) {
		countOne++;
	}
	if(b == c) {
		countOne++;
	}
	if(a == c) {
		countOne++;
	}

	if(countOne == 1) {
		cout << "Yes\n";
	} else {
		cout << "No\n";
	}
}