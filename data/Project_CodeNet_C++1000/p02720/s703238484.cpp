#include<bits/stdc++.h>

typedef long long ll;
typedef std::pair<ll, ll> P;
typedef std::tuple<ll, ll, ll> t3;
constexpr ll INF = 1e15;
constexpr ll mod = 1e9+7;

#define rep(i,n) for(int i = 0; i < int(n); i++)
using namespace std;

template<class T> inline bool chmax(T& a, const T& b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, const T& b) { if (b < a) { a = b; return 1; } return 0; }


class Divisor {
private:
	vector<ll> F;
public:
	Divisor(ll N) {
		for (ll i = 1; i * i <= N; i++) {
			if (N % i == 0) {
				F.push_back(i);
				if (i * i != N) F.push_back(N / i);
			}
		}
		sort(begin(F), end(F));
	}
	int size() { return F.size(); }
	ll operator[](int k) { return F[k]; }
	const vector<ll>& factors() { return F; }
};

int main() {
	ll k;
	cin >> k;
	vector<vector<ll>> dp(k, vector<ll>(10, 0));
	rep(i, 10) {
		dp[k - 1][i] = 1;
	}
	for (int i = k - 2; i >= 0; i--) {
		rep(j, 10) {
			for (int a : {-1, 0, 1}) {
				ll id = a + j;
				if (id < 0 || id > 9) continue;
				dp[i][j] += dp[i + 1][id];
				chmin(dp[i][j], INF);
			}
		}
	}
	vector<int> ans;
	int front = -1;
	ll prev = 0;
	int digit = 1;
	for (; digit <= k; digit++) {
		for (int j = 1; j < 10; j++) {
			ll next = dp[k - digit][j];
			if (prev + next >= k) {
				ans.push_back(j);
				front = j;
				break;
			}
			prev += next;
		}
		if (front >= 0) break;
	}
	for (int i = k - digit + 1; i < k; i++) {
		for (int a : {-1, 0, 1}) {
			ll j = a + front;
			if (j < 0 || j > 9) continue;
			ll next = dp[i][j];
			if (prev + next >= k) {
				ans.push_back(j);
				front = j;
				break;
			}
			prev += next;
		}
	}
	for (int i = 0; i < ans.size(); i++) {
		cout << ans[i];
	}
	cout << endl;
	return 0;
}
