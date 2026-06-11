#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

int main() {
	uint32_t A, B, C, D;
	cin >> A >> B >> C >> D;

	cout <<
		((uint32_t)((C + B - 1) / B) <= (uint32_t)((A + D - 1) / D) ? "Yes\n":"No\n");
	return 0;
}

