#include <vector>
#include <list>
#include <map>
#include <set>
#include <queue>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define trav(a, x) for(auto& a : x)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

const int maxn = 1e5 + 7;
ll dp[maxn], price[maxn];
int n, m;

int main() {
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(cin.failbit);
	priority_queue<ll> pq; 
	cin >> n >> m;
	rep(i, 0, n) {
		cin >> price[i];
		pq.push(price[i]);
	}
	rep(i, 0, m) {
		ll x = pq.top();
		pq.pop();
		x /= 2;
		pq.push(x);
	}
	ll sum = 0;
	while (!pq.empty()) {
		ll x = pq.top();
		pq.pop();
		sum += x;
	}
	cout << sum << endl;
}