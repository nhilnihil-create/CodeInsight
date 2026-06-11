#include <iostream>
using namespace std;

int main() {
	int a, b, c;
	cin >> a >> b >> c;
	bool ok = a == b || b == c || a == c;
	if(ok) {
		ok =(a != b) || (a != c);
	}
	cout << (ok ? "Yes" : "No");
}
