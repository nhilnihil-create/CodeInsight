#include <bits/stdc++.h>
using namespace std;
#define FOR(i,a,b) for(int i=(a);i<(b);i++)
#define REP(i,n) FOR(i,0,n)
#define ALL(v) (v).begin(),(v).end()
#define fi first
#define se second
template<typename A, typename B> inline bool chmax(A &a, B b) { if (a<b) { a=b; return 1; } return 0; }
template<typename A, typename B> inline bool chmin(A &a, B b) { if (a>b) { a=b; return 1; } return 0; }
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
const ll INF = 1ll<<30;
const ll longINF = 1ll<<60;
const ll MOD = 1000000007;
const double EPS = 1e-9;
const bool debug = 0;
//---------------------------------//

int N;
int A[112345];

int main() {
	cin >> N;
	REP(i, N) scanf("%d", A + i);
	
	sort(A, A + N);
	
	int ans = 0;
	vector<pii> ansv;
	
	int sum1 = A[N - 1], sum2 = A[0];
	int p = 1;
	while (p < N - 1) {
		ansv.push_back(pii(A[p] < 0 ? sum1 : sum2, A[p]));
		if (A[p] < 0) sum1 = sum1 - A[p];
		else sum2 = sum2 - A[p];
		p++;
	}
	ansv.push_back(pii(sum1, sum2));
	ans = sum1 - sum2;
	
	cout << ans << endl;
	REP(i, N - 1) printf("%d %d\n", ansv[i].fi, ansv[i].se);
	return 0;
}
