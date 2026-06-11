#include <iostream>
#include <vector>
#include <stack>
#include <queue>
#include <deque>
#include <map>
#include <unordered_map>
#include <set>
#include <string>
#include <bitset>
#include <algorithm>
#include <cstring>
#include <cmath>
#include <cstdlib>
#include <limits.h>
#define ll long long
#define pii pair<int, int>
#define pll pair<ll, ll>
#define INF 2e9 + 7
#define DIV 1000000007
#define pb push_back
#define all(v) (v).begin(), (v).end()
#define pi 3.14159265
#define MAX 400000

using namespace std;

int n;
vector<ll> p, m;
ll x, y;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> x >> y;
		p.pb(x + y);
		m.pb(x - y);
	}
	sort(all(p));
	sort(all(m));
	cout << max(p.back() - p[0], m.back() - m[0]);
	return 0;
}