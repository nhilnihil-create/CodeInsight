#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef pair<ll, ll> P;

#define REP(i, n) for (ll (i) = 0 ; (i) < (ll)(n) ; ++(i))
#define REPN(i, m, n) for (ll (i) = m ; (i) < (ll)(n) ; ++(i))
#define REP_REV(i, n) for (ll (i) = (ll)(n) - 1 ; (i) >= 0 ; --(i))
#define REPN_REV(i, m, n) for (ll (i) = (ll)(n) - 1 ; (i) >= m ; --(i))
#define ALL(x) x.begin(), x.end()

//#define INF (1e10)
#define MOD (1000000007)

#define print2D(h, w, arr) REP(i, h) { REP(j, w) cout << arr[i][j] << " "; cout << endl; }
template<class T> void print(const T& x) { cout << setprecision(16) << x << endl; }
template<class T, class... A> void print(const T& first, const A& ... rest) { cout << first << " "; prll(rest...); }
struct PreMain { PreMain() { cin.tie(0); ios::sync_with_stdio(false); } } premain;



int main() {
	ll N;
	cin >> N;
	int N2 = 1 << N;
	vector<int> A(N2);

	REP(i, N2) {
		cin >> A[i];
	}
	sort(A.begin(), A.end());
	
	vector<int> S;
	S.push_back(A.back());
	A.back() = -1;

	REP(i, N) {
		vector<int> P = S;
		sort(P.begin(), P.end());
		int Ai = (N2 - 1);
		while ((0 < P.size()) && (0 <= Ai)) {
			if (A[Ai] == -1) {
				Ai--;
				continue;
			}
			if (A[Ai] < P.back()) {
				S.push_back(A[Ai]);
				P.pop_back();
				A[Ai] = -1;
			}
			Ai--;
		}
		if (0 < P.size()) {
			print("No");
			return 0;
		}
	}
	print("Yes");
	return 0;
}
