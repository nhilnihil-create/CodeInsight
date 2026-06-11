#include <iostream>
#include <stack>
#include <queue>
#include <vector>
#include <algorithm>
#include <string>
#include <iomanip>
#include <functional>
#include <map>
#include <math.h>



using namespace std;

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);

	int a, b, c, d;
	cin >> a >> b >> c >> d;
	while (true) {

		c -= b;
		if (c <= 0) {
			cout << "Yes" << endl;
			return 0;
		}

		a -= d;
		if (a <= 0) {
			cout << "No" << endl;
			return 0;
		}
	}




	return 0;
}
