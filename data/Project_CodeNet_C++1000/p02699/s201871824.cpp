#include <iostream>
#include <cstdio>
using namespace std;

int s, w;
int main() {
	cin >> s >> w;
	cout << (w>=s ? "unsafe" : "safe");
	return 0;
}
