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

#define mod 1000000007;

int main(void) {

	ios::sync_with_stdio(false);
	cin.tie(0);

	long long int n, k;
	cin >> n >> k;
	long long int sum = 0, min = 0,max = 0;
	for (long long int i = 0; i <= n; i++) {
		min += i;
		max += n - i;
		if (i + 1 >= k) {
			sum += max - min + 1;
			sum %= mod;
		}
	}
	
	cout << sum << endl;








	return 0;
}
