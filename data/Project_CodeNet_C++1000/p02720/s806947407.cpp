#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <math.h>
#include <map>
#include <queue>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;
const int iINF = 1001001001;
const long long llINF = 1LL << 60;
int main()
{
	// ABC161-D, 1045, 
	ll k;
	cin >> k;
	queue<ll> que;
	for (int i = 1; i < 10; ++i) que.push(i);
	ll c = 0;
	ll ans = 0;
	while (c != k) {
		ans = que.front(); que.pop();
		if (ans % 10 != 0) {
			que.push(ans*ll(10) + ans % ll(10) - ll(1));
		}
		que.push(ans*ll(10) + ans % ll(10));
		if (ans % 10 != 9) {
			que.push(ans*ll(10) + ans % ll(10) + ll(1));
		}
		c++;
	}
	cout << ans << endl;
	return 0;
}