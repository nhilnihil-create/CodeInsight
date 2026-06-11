#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cmath>
#include <iomanip>

using namespace std;

int main() {
	long long A, B;
	cin >> A >> B;
	if (A > B) swap(A, B);
	long long C = B - A;
	if (C % 2 == 0) cout << C / 2 + A << endl;
	else cout << "IMPOSSIBLE" << endl;
	
	return 0;
}