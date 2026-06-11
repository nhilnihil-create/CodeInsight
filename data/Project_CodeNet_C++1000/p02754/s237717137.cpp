#include <iostream>
#include <string>
#include <vector>
#include <math.h>
#include <algorithm>
#include <utility>
typedef long long ll;
const int INF = 1e9+1;
const int MOD = 2e9 + 9;
const ll LINF = 1e18;
using namespace std;

int main() {
	long long int n, a, b;
	long long  int ans;

	cin >> n >> a >> b;

	ans = a * (n / (a + b));

	if (n % (a + b) > a) {
		ans +=a;
	}
	else{
		ans += n % (a + b);
	}
	cout << ans << endl;

}