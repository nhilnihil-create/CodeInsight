#include<bits/stdc++.h>
typedef long long ll;
typedef std::pair<ll, ll> P;

#define rep(i,n) for(int i = 0; i < int(n); i++)
using namespace std;

template<class T> inline bool chmax(T& a, const T& b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, const T& b) { if (b < a) { a = b; return 1; } return 0; }

int main() {
	ll n;
	cin >> n;
	vector<ll> vs(n);
	rep(i, n) cin >> vs[i];
	sort(vs.begin(), vs.end());
	ll sum = 0;
	for (int i = 0; i < n; i++) {
		for (int j = i + 1; j < n; j++) {
			ll a = vs[i] + vs[j];
			auto l = std::lower_bound(vs.begin() + j, vs.end(), a);
			advance(l, -1);
			auto d = l - (vs.begin() + j);
			sum += d;
		}
	}
	cout << sum << endl;
	return 0;
}
