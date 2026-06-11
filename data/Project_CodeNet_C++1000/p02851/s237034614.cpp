#include <iostream>
#include <iomanip>
#include <vector>
#include <set>
#include <string>
#include <queue>
#include <algorithm>
#include <map>
#include <cmath>
#include <numeric>
#include <list>
#include <stack>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <tuple>

#define rep(i, n) for (int i = 0; i < (n); i++)
#define rep1(i, n) for (int i = 1; i <= (n); i++)
#define show(a, n) rep(i,n) {cout<<a[i]<<' ';} cout<<endl;

using namespace std;
typedef vector<int> vi;
typedef pair<int, int> pii;
typedef long long ll;
typedef pair<long long, long long> pll;

const int INF = 1 << 30;
const long long INFL = 1LL << 62;
const int MOD = 1000000007;
const int MAX = 100000;
const int N = 100010;

int main() {
	ll n, k;
	cin >> n >> k;
	vector<ll> a(n);
	rep(i, n) {
		cin >> a[i];
		a[i]--;
	}

	vector<ll> suba(n + 1);
	suba[0] = 0;
	rep(i, n) {
		suba[i + 1] = suba[i] - a[i];
		suba[i + 1] = suba[i + 1] % k;
		if(suba[i + 1] < 0) suba[i + 1] += k;
	}

	ll ans = 0;
	map<ll, ll> mp;
	rep(i, n) {
		mp[suba[i]]++;
		if(i >= k - 1) mp[suba[i - k + 1]]--;
		ans += mp[suba[i + 1]];
	}
	cout << ans << endl;
}
