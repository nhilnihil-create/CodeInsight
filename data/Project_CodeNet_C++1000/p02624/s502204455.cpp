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
	int n;
	cin >> n;
	vector<int> cnt(n + 1, false);
	for (int i = 2; i <= n; ++i)
		if (i * 2 <= n)
			for (int j = i * 2; j <= n; j += i)
				cnt[j]++;
	ll ans = 1;
	for (int i = 2; i <= n; ++i)
		ans += (cnt[i] + 2) * 1ll * i;
	cout << ans;
}