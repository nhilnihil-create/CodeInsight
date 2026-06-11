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

vi v;

int parity(int n, int r, int k) {
	if(n == 0 || n == 1) return 1;
	if(n < v[k-1]) {
		return parity(n, r, k-1);
	}
	else if(r < n+1-v[k-1]) {
		return parity(n-v[k-1], r, k-1);
	}
	else if(r > v[k-1]-1) {
		return parity(n-v[k-1], r-v[k-1], k-1);
	}
	else {
		return 0;
	}
}

int main() {
//	cout << fixed << setprecision(15);
	int n;
	string s;
	cin >> n >> s;

	if(n == 1) { cout << s << endl; return 0; }

	int b = 1;
	rep(i, 21) { v.push_back(b); b *= 2; }

	bool has2 = false;
	rep(i, n) if(s[i] == '2') {has2 = true; break; }

	char c;
	if(has2) c = '2';
	else c = '3';

	int ans = 0;
	rep(i, n) if(s[i] == c) ans += parity(n-1, i, 20);
	ans %= 2;
	if(!has2) ans *= 2;
	cout << ans << endl;
}
