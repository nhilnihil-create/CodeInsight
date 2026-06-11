#include <iostream>
#include <algorithm>
using namespace std;

int main() {
	int h, w, n;
	cin >> h >> w >> n;
	cout << (n % max(h, w) ? n / max(h, w) + 1 : n / max(h, w)) << endl;
	return 0;
}