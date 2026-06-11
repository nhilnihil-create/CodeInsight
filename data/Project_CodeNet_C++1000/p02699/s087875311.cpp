#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <iomanip>
#include <algorithm>

using namespace std;
using ll = long long;
using pint = pair<int, int>;

int main() {
	int S, W;
	cin >> S >> W;

	cout << ((S <= W) ? "unsafe" : "safe") << endl;
	return 0;
}
