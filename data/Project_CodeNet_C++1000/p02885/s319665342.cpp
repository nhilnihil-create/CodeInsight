#include <bits/stdc++.h>
using namespace std;

int main() {
	int a, b;
	cin >> a >> b;
	if (a > b + b) {
	    cout << a - 2 * b << "\n";
	}
    else {
        cout << "0" << "\n";
    }
	return 0;
}