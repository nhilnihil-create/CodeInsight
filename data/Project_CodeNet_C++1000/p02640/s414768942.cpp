#include <iostream>
#include <math.h>
#include <algorithm>
#include <string>
#include <map>
#include <vector>
#include <cmath>

using namespace std;

void b_crane_and_turtle(void) {
	int x, y;
	cin >> x >> y;
	int total = 0;
	string judge = "No";
	for (int j = 0; j <= x; j++) {
		total = 2 * j + 4 * (x - j);
		if (total == y) {
			judge = "Yes";
			break;
		}
	}
	cout << judge << endl;
}

int main()
{
    b_crane_and_turtle();
    return 0;
}