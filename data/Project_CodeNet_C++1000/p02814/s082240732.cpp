#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <stack>
#include <queue>
#include <set>
#include <map>
#include <algorithm>
#include <iomanip>
#include <math.h>
#include <string.h>
#include <cstdio>
#include <tuple>
#include <numeric>
#include <time.h>
#include <chrono>
#ifdef _MSC_VER
#  include <intrin.h>
#  define __builtin_popcount __popcnt
#endif
#define FOR(i,a,b) for(ll i=a;i<b;i++)
#define REP(i,a,b) for(ll i=a;i>b;i--)
#define CST(x) cout<<fixed<<setprecision(x)//小数点以下の桁数指定
#define ct(a) cout<<a<<endl
#define rep(i,n) for(int i=0;i<(n);i++)
#define repl(i,l,r) for(int i=(1);i<(r);i++)
#define per(i, n) for(int i = ((n)-1); i >= 0; i--)
static const double pi = 3.141592653589793;
using namespace std;
typedef long long ll;
const ll MOD = 998244353;
const ll INF = (1LL << 31) - 1;
const ll mod = 1e9 + 7;

ll gcd(ll a, ll b) {
	if (a < b)swap(a, b);
	ll r = a % b;
	while (r != 0) {
		a = b; b = r; r = a % b;
	}
	return b;
}

ll lcm(ll a, ll b) {
	ll g = gcd(a, b);
	return a * b / g;
}

int main() {
	cin.tie(0);
	cout.tie(0);
	ios::sync_with_stdio(false);


	ll N, M,L=1;
	ll two = 0;
	cin >> N >> M;
	FOR(i, 0, N) {
		ll cur; cin >> cur;

		ll copy = cur;
		ll cnt = 0;
		while (copy % 2 == 0) {
			copy /= 2;
			cnt++;
		}

		if (i == 0) {
			two = cnt;
		}
		else {
			if (two != cnt) {
				cout << 0 << endl;
				return 0;
			}
		}

		L = lcm(L, cur/2);
		if (L > 1e9) {
			cout << 0 << endl;
			return 0;
		}
	}
	cout << (M + L) / (2 * L) << endl;



}