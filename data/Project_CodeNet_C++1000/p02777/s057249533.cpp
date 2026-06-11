#include <iostream>
#include <cstdio>
using namespace std;

string s, t, u;
int a, b;
int main() {
	cin >> s >> t >> a >> b >> u;
	s==u ? a-- : b--;
	cout << a << ' ' << b;
	return 0;
}
