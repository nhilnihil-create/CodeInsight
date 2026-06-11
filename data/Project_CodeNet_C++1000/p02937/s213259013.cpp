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
	string s, t;
	cin >> s >> t;

	vector<vi> v(26);
	rep(i, s.size()) v[s[i] - 'a'].push_back(i);

	const int smax = s.size() + 10;
	rep(i, 26) v[i].push_back(smax);
	ll cycle = 0, cur = -1, i = 0;

	while(i < t.size()) {
		vi& v2 = v[t[i] - 'a'];
		if(v2.size() == 1) {
			cycle = -1;
			break;
		}
		cur = *upper_bound(v2.begin(), v2.end(), cur);
		if(cur == smax) {
			cycle++;
			cur = -1;
		}
		else i++;
	}
	if(cycle == -1) cout << -1 << endl;
	else cout << cycle * s.size() + cur + 1 << endl;
}
