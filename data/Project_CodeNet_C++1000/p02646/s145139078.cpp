#include <bits/stdc++.h>
using namespace std;

long long a, v, b, w, t;

int main() {
	cin >> a >> v >> b >> w >> t;
	cout << (abs(a - b) <= (v - w) * t ? "YES" : "NO") << endl;
}
