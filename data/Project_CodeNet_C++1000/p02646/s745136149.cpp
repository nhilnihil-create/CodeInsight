#include<iostream>

using namespace std;

int main() {
	long long a, b, v, w, t;
	cin >> a >> v;
	cin >> b >> w;
	cin >> t;

	if ((v - w) * t >= abs(a - b)) {
		cout << "YES" << endl;
		return 0;
	}
	else {
		cout << "NO" << endl;
		return 0;
	}
}