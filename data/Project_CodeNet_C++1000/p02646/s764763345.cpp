#include <iostream>
using namespace std;

long long a, b, v, w, t;

int main() {
	cin >> a >> v >> b >> w >> t;
	if (v * t >= abs(b - a) + t * w)
		cout << "YES\n";
	else
		cout << "NO\n";
}