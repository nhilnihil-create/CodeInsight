#include <iostream>
#include <algorithm>
using namespace std;

long long int INF = -1000000000000000001;

int main(void) {

	long long int a, b, c, d;
	cin >> a >> b >> c >> d;

	long long int ans = INF;

	ans = max(ans, a*c);
		ans = max(ans, a*d);
		ans = max(ans, b*c);
		ans = max(ans, b*d);

		cout << ans << endl;

	return 0;
}