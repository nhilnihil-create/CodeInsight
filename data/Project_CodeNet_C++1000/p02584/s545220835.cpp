#define _USE_MATH_DEFINES
#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <bitset>
#include <stack>
#include <deque>
#include <set>
#include <unordered_set>
#include <list>
#include <map>
#include <unordered_map>
#include <algorithm>
#include <cmath>
#include <climits>
#include <ctime>
#include <random>
#define speed ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define ll long long
#define eps 1e-9
#define inf 0x3f3f3f3f
#define mod 1000000007
using namespace std;

int main() {
	speed;
	ll x, k, d;
	cin >> x >> k >> d;
	x = abs(x);
	/*if (k * d > x && (x / d + 1)* d <= k * d) {
		ll p1 = x - (x / d) * d, p2 = x - (x / d + 1) * d;
		if (abs(p1) <= abs(p2))
			ans = p1;
		else
			ans = p2;
	}
	else
		ans = x - k * d;*/
	ll t = min(x / d, k);
	k -= t;
	x = x - t * d;
	if (k % 2) {
		if (x < 0)
			x += d;
		else
			x -= d;
	}
	cout << abs(x);
}