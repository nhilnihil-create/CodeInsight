#include "bits/stdc++.h"
using namespace std;
using lint = long long int;
using pint = pair<int, int>;
using plint = pair<lint, lint>;
#define ALL(x) (x).begin(), (x).end()
#define SZ(x) ((lint)(x).size())
#define POW2(n) (1LL << (n))
#define FOR(i, begin, end) for(lint i=(begin),i##_end_=(end);i<i##_end_;i++)
#define IFOR(i, begin, end) for(lint i=(end)-1,i##_begin_=(begin);i>=i##_begin_;i--)
#define REP(i, n) FOR(i,0,n)
#define IREP(i, n) IFOR(i,0,n)
template<class T>bool chmax(T & a, const T & b) { if (a < b) { a = b; return 1; } return 0; }
template<class T>bool chmin(T & a, const T & b) { if (b < a) { a = b; return 1; } return 0; }
template<typename T1, typename T2> pair<T1, T2> operator+(const pair<T1, T2>& l, const pair<T1, T2>& r) { return make_pair(l.first + r.first, l.second + r.second); }
template<typename T1, typename T2> pair<T1, T2> operator-(const pair<T1, T2>& l, const pair<T1, T2>& r) { return make_pair(l.first - r.first, l.second - r.second); }
const lint MOD = 1e9 + 7;

lint N, A, B;
map<plint, lint> cnt;
plint arr[50];
int main() {
	cin.tie(0); ios_base::sync_with_stdio(false);
	cin >> N;
	REP(i, N) {
		cin >> A >> B;
		arr[i] = plint(A, B);
	}
	sort(arr, arr + N);
	REP(i, N - 1) {
		FOR(j, i + 1, N) {
			plint range = arr[i] - arr[j];
			cnt[range]++;
		}
	}
	lint maxv = 0;
	for (auto itr : cnt) {
		chmax(maxv, itr.second);
	}
	cout << N - maxv;
}
