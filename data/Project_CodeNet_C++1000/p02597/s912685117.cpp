#include <bits/stdc++.h>
using namespace std;
#define REP(i, n) FOR(i, 0, (n))
#define FOR(i, a, b) for(int i=(a); i<(b); i++)
#define LAR(a, b) ((a)=max((a),(b)))
#define SML(a, b) ((a)=min((a),(b)))
using ll = long long;
using ld = long double;
using vi = vector<int>;
using vl = vector<ll>;
using pii = pair<int, int>;
using vpii = vector<pair<int, int>>;
template<typename T>
using pque = priority_queue<T, vector<T>, greater<T>>;
#define PB push_back
#define EB emplace_back
#define MP make_pair
#define ALL(a) (a).begin(), (a).end()
#ifdef LOCAL_DEBUG
#define DEBUG(...) printf(__VA_ARGS__)
#else
#define DEBUG(...)
#endif

char s[212345];

int main(){
	int n; scanf("%d%s", &n, s);
	int p = 0, q = 0;
	REP(i, n) if(s[i] == 'R') q++;
	int ans = INT_MAX;
	REP(i, n+1){
		SML(ans, max(p, q));
		if(s[i] == 'R') q--;
		if(s[i] == 'W') p++;
	}
	printf("%d\n", ans);
}
