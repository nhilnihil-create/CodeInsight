#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> pii;
typedef long long ll;
template<class T> using V = vector<T>;
template<class T> using VV = V<V<T>>;

#define pb push_back
#define eb emplace_back
#define mp make_pair
#define fi first
#define se second
#define rep(i,n) rep2(i,0,n)
#define rep2(i,m,n) for(int i=m;i<(n);i++)
#define ALL(c) (c).begin(),(c).end()
#define dump(x) cerr << #x << " = " << (x) << endl
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

int main() {
	int N; cin >> N;
	bool p2 = 0;
	{
		int x = N;
		while (x%2==0) {
			x/=2;
		}
		p2 = (x == 1);
	}

	if (p2) {
		puts("No");
		return 0;
	}

	puts("Yes");
	V<pii> vec;

	vec.eb(1, 2);
	vec.eb(2, 3);
	vec.eb(3, N+1);
	vec.eb(N+1, N+2);
	vec.eb(N+2, N+3);

	for (int i = 5; i <= N; i += 2) {
		vec.eb(1, i-1);
		vec.eb(1, i);
		vec.eb(i-1, i+N);
		vec.eb(i, i-1+N);
	}

	if (N % 2 == 0) {
		int a = -1, b = -1;
		for (int i = 2; i < N; ++i) {
			int to = (N ^ 1 ^ i);
			if (to >= 2 && to < N) {
				a = i, b = to;
				break;
			}
		}
		vec.eb(a, N);
		vec.eb(b, N+N);
	}

	for (auto e : vec) {
		printf("%d %d\n", e.fi, e.se);
	}

	return 0;
}