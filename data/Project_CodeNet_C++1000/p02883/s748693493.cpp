#include"bits/stdc++.h"
using namespace std;
using lint = long long int;
using pint = pair<int, int>;
using plint = pair<lint, lint>;
#define ALL(x) (x).begin(), (x).end()
#define SZ(x) ((lint)(x).size())
#define POW2(n) (1LL << (n))
#define FOR(i, begin, end) for(int i=(begin),i##_end_=(end);i<i##_end_;i++)
#define IFOR(i, begin, end) for(int i=(end)-1,i##_begin_=(begin);i>=i##_begin_;i--)
#define REP(i, n) FOR(i,0,n)
#define IREP(i, n) IFOR(i,0,n)
template<typename T1, typename T2> pair<T1, T2> operator+(const pair<T1, T2> & l, const pair<T1, T2> & r) { return make_pair(l.first + r.first, l.second + r.second); }
template<typename T1, typename T2> pair<T1, T2> operator-(const pair<T1, T2> & l, const pair<T1, T2> & r) { return make_pair(l.first - r.first, l.second - r.second); }
lint N, K, a, f;
vector<lint> A, F;

bool check(lint val) {
	lint rest = K;
	REP(i, N) {
		lint y = ((A[i] * F[i] - val - 1) / F[i] + 1);
		if ((A[i] * F[i] - val) <= 0) {
			y = 0ll;
		}
		lint x = max(0ll, y);
		rest -= x;
	}
	return rest < 0 ? true : false;
}

int main() {
	cin.tie(0); ios_base::sync_with_stdio(false);
	cin >> N >> K;
	REP(i, N) {
		cin >> a;
		A.push_back(a);
	}	
	REP(i, N) {
		cin >> f;
		F.push_back(f);
	}
	sort(ALL(A));
	sort(ALL(F));
	reverse(ALL(F));
	lint lb = -1, ub = 1e12+1;
	while (ub - lb > 1) {
		lint mid = (lb + ub) / 2;
		if (check(mid)) lb = mid;
		else ub = mid;
	}
	cout << ub;
}
