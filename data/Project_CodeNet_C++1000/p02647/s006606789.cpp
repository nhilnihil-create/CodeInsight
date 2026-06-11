#include <algorithm>  
#include <iostream>  
#include <sstream>  
#include <string>  
#include <vector>  
#include <queue>  
#include <set>  
#include <map>  
#include <cstdio>  
#include <cstdlib>  
#include <cctype>  
#include <cmath>  
#include <cstring>
#include <list>  
#include <cassert>
#include <climits>
#include <bitset>
#include <chrono>
#include <random>
using namespace std;

#define PB push_back  
#define MP make_pair  
#define SZ(v) ((int)(v).size())  
#define FOR(i,a,b) for(int i=(a);i<(b);++i)  
#define REP(i,n) FOR(i,0,n)  
#define FORE(i,a,b) for(int i=(a);i<=(b);++i)  
#define REPE(i,n) FORE(i,0,n)  
#define FORSZ(i,a,v) FOR(i,a,SZ(v))  
#define REPSZ(i,v) REP(i,SZ(v))  
std::mt19937 rnd((int)std::chrono::steady_clock::now().time_since_epoch().count());
typedef long long ll;
ll gcd(ll a, ll b) { return b == 0 ? a : gcd(b, a % b); }

const int MAXN = 200000;

int n, nop;
int a[MAXN];
int ans[MAXN];

int cur[MAXN];
int nxt[MAXN + 1];

void solve() {
	REP(i, n) cur[i] = a[i];
	REP(op, nop) {
		bool done = true; REP(i, n) if (cur[i] != n) done = false; if (done) break;
		REPE(i, n) nxt[i] = 0;
		REP(i, n) {
			int d = cur[i], l = max(0, i - d), r = min(n - 1, i + d);
			++nxt[l], --nxt[r + 1];
		}
		REP(i, n) nxt[i + 1] += nxt[i];
		REP(i, n) cur[i] = nxt[i];
	}
	REP(i, n) ans[i] = cur[i];
}

void run() {
	scanf("%d%d", &n, &nop);
	REP(i, n) scanf("%d", &a[i]);
	solve();
	REP(i, n) { if (i != 0) printf(" "); printf("%d", ans[i]); } puts("");
}

int main() {
	run();
	return 0;
}
