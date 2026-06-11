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
#include <list>

using namespace std;

int main(void) {

	ios::sync_with_stdio(false);
	cin.tie(0);

	long long int n; cin >> n;
	long long int sum = 0;
	for (int i = 1; i <= n; i++) {
		if (i % 3 && i % 5) sum += i;
	}
	cout << sum << endl;
	return 0;
}
