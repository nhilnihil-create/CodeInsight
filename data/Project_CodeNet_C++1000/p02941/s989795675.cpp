#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> pii;
typedef long long ll;
typedef vector<int> vi;

#define pb push_back
#define eb emplace_back
#define mp make_pair
#define fi first
#define se second
#define rep(i,n) rep2(i,0,n)
#define rep2(i,m,n) for(int i=m;i<(n);i++)
#define ALL(c) (c).begin(),(c).end()
#define dump(x) cout << #x << " = " << (x) << endl
constexpr ll TEN(int n) { return (n == 0) ? 1 : 10 * TEN(n-1); }

template<class T, class U> void chmin(T& t, const U& u) { if (t > u) t = u; }
template<class T, class U> void chmax(T& t, const U& u) { if (t < u) t = u; }

template<class T, class U>
ostream& operator<<(ostream& os, const pair<T, U>& p) {
	os<<"("<<p.first<<","<<p.second<<")";
	return os;
}

template<class T>
ostream& operator<<(ostream& os, const vector<T>& v) {
	os<<"{";
	rep(i, v.size()) {
		if (i) os<<",";
		os<<v[i];
	}
	os<<"}";
	return os;
}

const ll INF = TEN(18);
const int maxn = 200010;

int N;
int A[maxn], B[maxn];

bool check(int p) {
	int l = p-1;
	if (l < 0) l += N;
	int r = p+1;
	if (r >= N) r -= N;
	return A[p] != B[p] && B[p] >= B[l] + B[r];
}

int main() {
	cin >> N;
	queue<int> que;

	rep(i, N) cin >> A[i];
	rep(i, N) cin >> B[i];

	ll ans = 0;
	rep(i, N) {
		if (check(i)) {
			que.push(i);
		}
	}

	while (!que.empty()) {
		int i = que.front(); que.pop();
		if (!check(i)) continue;

		int l = i-1;
		if (l < 0) l += N;
		int r = i+1;
		if (r >= N) r -= N;


		ll dec = B[l] + B[r];
		ll num = INF;
		if (A[i] >= dec) {
			if ((B[i] - A[i]) % dec != 0) {
				puts("-1");
				return 0;
			} else {
				num = (B[i] - A[i]) / dec;
				B[i] -= num * dec;
			}
		} else {
			num = (B[i] - dec) / dec;
			B[i] -= num * dec;
			if (B[i] > dec) {
				++num;
				B[i] -= dec;
			}
		}
		ans += num;
		if (check(l)) {
			que.push(l);
		}
		if (check(r)) {
			que.push(r);
		}
	}

	bool ok = 1;
	rep(i, N) if (A[i] != B[i]) {
		ok = 0;
	}

	if (ok) {
		cout << ans << endl;
	} else {
		puts("-1");
	}

	return 0;
}