#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <iomanip>
#include <vector>
#include <string.h>
#include <math.h>
#include <algorithm>

using namespace std;

int main() {
	
	long long a, b, n;
	cin >> a >> b >> n;
	long long ans = -1;

	/*for (int i = 1;i <= n;i++) {
		long long tmp = (long long)floorl(a * i / b) - a * (long long)floorl(i / b);
		ans = max(ans, tmp);
	}

	cout << ans << endl;*/

	if (n >= b - 1 && b != 1)  {
		long long i = b - 1;
		ans = (long long)floorl(a * i / b) - a * (long long)floorl(i / b);
	}
	else {
		long long i = n;
		ans = (long long)floorl(a * i / b) - a * (long long)floorl(i / b);
	}


	cout << ans << endl;
	return 0;
}