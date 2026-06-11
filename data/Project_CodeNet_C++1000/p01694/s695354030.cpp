#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>
#include <cstdio>
#include <functional>
#include <numeric>
#include <stack>
#include <queue>
#include <map>
#include <set>
#include <utility>
#include <sstream>
#include <complex>
#include <fstream>
#include <bitset>
#include <time.h>

using namespace std;

typedef long long ll;
typedef pair<ll, ll> P;
typedef vector<ll> V;
typedef complex<double> Point;

#define PI acos(-1.0)
#define EPS 1e-10
const ll INF = (1LL << 31) - 1;
const ll MOD = 1e9 + 7;

#define FOR(i,a,b) for(int i=(a);i<(b);i++)
#define REP(i,N) for(int i=0;i<(N);i++)
#define ALL(s) (s).begin(),(s).end()
#define EQ(a,b) (abs((a)-(b))<EPS)
#define EQV(a,b) ( EQ((a).real(), (b).real()) && EQ((a).imag(), (b).imag()) )
#define fi first
#define se second
#define N_SIZE (1LL << 20)
#define NIL -1
#define MAX_N 100100 * 3

int n;

int main() {
	while (cin >> n&&n) {
		bool f = 1;
		int ans = 0;
		bool rn[2] = { 0,-1 }, ln[2] = { 0,-1 };
		REP(i, n) {
			string s;
			cin >> s;
			if (s == "lu") {
				ln[0] = 1;
			}
			else if (s == "ru") {
				rn[0] = 1;
			}
			else if (s == "ld") {
				ln[0] = 0;
			}
			else {
				rn[0] = 0;
			}
			if (ln[1] != ln[0] || rn[1] != rn[0]) {
				if (ln[0] == rn[0]) {
					if (f == ln[0]) {
						ans++;
						f = !f;
					}
				}
			}
			ln[1] = ln[0];
			rn[1] = rn[0];
		}
		cout << ans << endl;
	}
}