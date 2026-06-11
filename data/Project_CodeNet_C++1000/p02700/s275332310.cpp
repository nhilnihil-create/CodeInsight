#include <iostream>
#include <math.h>
#include <algorithm>
#include <string>
#include <map>
#include <vector>

using namespace std;

void b_battle(void) {
	int a, b, c, d;
	cin >> a >> b >> c >> d;

	bool turn_a = true;
	while ((a > 0) && (c > 0)) {
		if (turn_a) {
			c -= b;
		}
		else {
			a -= d;
		}
		turn_a = !turn_a;
	}
	if (a > 0) cout << "Yes" << endl;
	else       cout << "No" << endl;
}

int main()
{
    b_battle();

    return 0;
}