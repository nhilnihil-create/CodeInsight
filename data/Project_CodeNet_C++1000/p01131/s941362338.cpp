#define  _CRT_SECURE_NO_WARNINGS
#include "bits/stdc++.h"
#pragma comment (linker, "/STACK:526000000")

using namespace std;
typedef string::const_iterator State;
#define eps 1e-11L
#define MAX_MOD 1000000007LL
#define GYAKU 500000004LL

#define MOD 998244353LL
#define seg_size 262144*2LL
#define pb push_back
#define mp make_pair
typedef long long ll;
#define REP(a,b) for(long long (a) = 0;(a) < (b);++(a))
#define ALL(x) (x).begin(),(x).end()

unsigned long xor128() {
	static unsigned long x = 123456789, y = 362436069, z = 521288629, w = time(NULL);
	unsigned long t = (x ^ (x << 11));
	x = y; y = z; z = w;
	return (w = (w ^ (w >> 19)) ^ (t ^ (t >> 8)));
}

void init() {
	iostream::sync_with_stdio(false);
	cout << fixed << setprecision(10);
}

#define int ll
void solve() {
		string s;
		cin >> s;
		string sup[10] = { "1111",".,!? ","abc" , "def","ghi","jkl","mno","pqrs","tuv","wxyz" };
		int now = -1;
		int target = -1;
		REP(q, s.length()) {
			if (s[q] == '0') {
				if (target != -1) {
					cout << sup[target][now % sup[target].length()];
				}
				target = -1;
				now = -1;
			}
			else {
				now++;
				target = s[q] - '0';
			}
		}
		cout << endl;
}
#undef int

int main() {
	init();
	int test;
	cin >> test;
	REP(te,test)
	solve();
}
