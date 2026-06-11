#include <iostream>
#include <cstdio>
#include <cmath>
using namespace std;

long long a, v, b, w, t;
int main() {
	cin >> a >> v >> b >> w >> t;
	cout << (v>w && abs(b-a)<=t*(v-w) ? "YES" : "NO");
	return 0;
}
