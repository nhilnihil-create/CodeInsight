#include <iostream>
#include <string>
#include <vector>
#include <math.h>
#include <algorithm>
#include <utility>
typedef long long ll;
const int INF = 1e9;
const int MOD = 1e9 + 7;
const ll LINF = 1e18;
using namespace std;
int main() {
	long long int n, k;
	cin >> n >> k;
	cout << min(n % k, abs(n % k - k)) << endl;
		return 0;
}
