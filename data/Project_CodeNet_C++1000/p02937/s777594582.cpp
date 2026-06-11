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


string s, t;
ll ans;
bool canflag = false;
vector<ll> V[26];


int main() {
	cin.tie(0);
	cout.tie(0);
	ios::sync_with_stdio(false);

	cin >> s >> t;


	FOR(i, 0, s.length()) {
		V[int(s[i] - 'a')].push_back(i);
	}

	int now = s.length()-1;
	FOR(i, 0, t.length()) {
		int cur = int(t[i] - 'a');

		if (V[cur].empty()) {
			canflag = true;
			break;
		}
		auto ite = upper_bound(V[cur].begin(),V[cur].end(), now);
		if (ite == V[cur].end()) {
			ans =(ans + (s.length() - now)+V[cur][0]);
			now = V[cur][0];
		}
		else {
			ans =(ans+ *ite - now);
			now = *ite;
		}


		//cout << ans << endl;
	}

	if (canflag) {
		cout << -1 << endl;
	}
	else {
		cout << ans << endl;
	}


}
