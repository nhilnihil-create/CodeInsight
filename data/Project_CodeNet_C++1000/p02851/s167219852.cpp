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
	vector<ll> s(n + 1);
	s[0] = 0;
	rep(i, n) {
		ll a;
		cin >> a;
		s[i + 1] = s[i] + a;
	}

	map<ll, ll> mp;
	ll ans = 0;
	for(int i = 1; i <= n; i++) {
		mp[(s[i - 1] - (i - 1)) % k]++;
		if(i - k >= 0) mp[(s[i - k] - (i - k)) % k]--;
		ans += mp[(s[i] - i) % k];
	}
	cout << ans << endl;
}
