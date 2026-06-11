#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cmath>
#include <iomanip>

using namespace std;

int main() {
	int A, B, C;
	cin >> A >> B >> C;
	if (C - (A - B) > 0) cout << C - (A - B) << endl;
	else cout << 0 << endl;
	return 0;
}