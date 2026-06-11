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

ll a[212345];

int main(){
	int n; ll k; scanf("%d%lld", &n, &k);
	REP(i, n) scanf("%lld", a+i);
	ll mi = 0, mx = 1'000'000'007; //mi->ng mx->ok
	while(mx-mi>1){
		ll md = (mi+mx)/2, sm = 0;
		REP(i, n) sm += (a[i] - 1) / md;
		if(sm <= k) mx = md;
		else mi = md;
	}
	printf("%lld\n", mx);
}
