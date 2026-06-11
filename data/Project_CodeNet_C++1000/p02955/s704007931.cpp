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
#define show(a, n) rep(i,n) {cout<<a[i]<<' ';} cout<<endl
#define show2(a, n, m) rep(i, n) { rep(j, m) {cout << a[i][j] << ' ';} cout << endl;} 
#define chmin(a, b) a = min(a, b)
#define chmax(a, b) a = max(a, b)

using namespace std;
typedef vector<int> vi;
typedef pair<int, int> pii;
typedef long long ll;
typedef vector<ll> vll;
typedef pair<long long, long long> pll;
typedef long double ld;

const int INF = 1 << 30;
const long long INFL = 1LL << 60;
const int MOD = 1000000007;
const int MAX = 100000;
const int N = 100010;

int main() {
//	cout << fixed << setprecision(15);
	ll n, k;
	cin >> n >> k;
	vll a(n);
	rep(i, n) cin >> a[i];

	ll asum = 0;
	rep(i, n) asum += a[i];

	map<ll, int> mp;
	for(ll i = 2; i * i <= asum; i++) {
		while(asum % i == 0) {
			mp[i]++;
			asum /= i;
		}
	}
	if(asum > 1) mp[asum]++;

	vll cdiv(1, 1);
	for(auto i = mp.begin(); i != mp.end(); i++) {
		ll size = cdiv.size();
		rep(j, size) for(ll k = 1; k <= i->second; k++) {
			cdiv.push_back(cdiv[j] * pow(i->first, k));
		}
	}
	sort(cdiv.begin(), cdiv.end(), greater<ll>());

	vll diff(n);
	for(auto i: cdiv) {
		rep(j, n) {
			diff[j] = a[j] % i;
			if(diff[j] > i - diff[j]) diff[j] -= i;
		}
//		cout << i << ":";
//		show(diff, n);

		ll sumd = 0;
		rep(j, n) sumd += diff[j];
		sort(diff.begin(), diff.end());
		int j, dj;
		if(sumd > 0) j = n - 1, dj = -1;
		else if(sumd < 0) j = 0, dj = 1;
		while(sumd != 0) {
			ll new_diff = diff[j] % i + dj * i;
			ll diff_diff = new_diff - diff[j];
			if(abs(sumd) > abs(diff_diff)) {
				sumd += diff_diff;
				diff[j] = new_diff;
			}
			else {
				diff[j] -= sumd;
				sumd = 0;
			}
			j += dj;
		}
		sumd = 0;
		rep(j, n) if(diff[j] > 0) sumd += diff[j];
//		cout << i << ":";
//		show(diff, n);
		if(sumd <= k) {
			cout << i << endl;
			break;
		}
	}
}
