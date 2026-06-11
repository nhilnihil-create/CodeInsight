#define _USE_MATH_DEFINES
#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
const int INF = 1e9;
const ll MOD = 1e9 + 7;
const ll MOD2 = 998244353;
const ll LINF = 1e18;
#define y0 y3487465
#define y1 y8687969
#define j0 j1347829
#define j1 j234892
#define next asdnext
#define prev asdprev
#define MP make_pair
#define F first
#define S second
#define PB push_back
#define dump(x)  cout << #x << " = " << (x) << endl;	// debug
#define SZ(x) ((ll)(x).size())
#define FOR(i, a, b) for (ll i = (a); i <= (b); i++)
#define RFOR(i, a, b) for (ll i = (a); i >= (b); i--)
#define ps(s) cout << #s << endl;
#define pv(v) cout << (v) << endl;
#define pvd(v) cout << setprecision(16) << (v) << endl;
#define ALL(a)  (a).begin(),(a).end()
#define RANGE(a, left, right)  (a).begin()+(left),(a).begin()+(right)	// left to (right-1)

int main() {
	string s;
	ll k;
	cin >> s >> k;
	int len = s.size();

	int cnt1 = 0;
	string s1 = s;
	int cnt2 = 0;
	string s2 = s;
	int cnt3 = 0;
	string s3 = s;

	FOR(j, 1, len - 1) {
		if (s1[j] == s1[j - 1]) {
			cnt1++;
			s1[j] = '?';
		}
	}

	if (s2[0] == s1[len - 1]) {
		cnt2++;
		s2[0] = '?';
	}
	FOR(j, 1, len - 1) {
		if (s2[j] == s2[j - 1]) {
			cnt2++;
			s2[j] = '?';
		}
	}

	if (s3[0] == s2[len - 1]) {
		cnt3++;
		s3[0] = '?';
	}
	FOR(j, 1, len - 1) {
		if (s3[j] == s3[j - 1]) {
			cnt3++;
			s3[j] = '?';
		}
	}
	
	ll res = cnt1;
	k--;
	ll loop2 = (k + 1) / 2;
	res += loop2 * cnt2;
	ll loop3 = k / 2;
	res += loop3 * cnt3;

	pv(res)

	return 0;
}