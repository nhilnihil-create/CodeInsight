#pragma GCC optimize("O3")
#pragma GCC optimize ("unroll-loops")
#pragma GCC target ("avx")
#define io_init cin.tie(0);ios::sync_with_stdio(0);cout<<setprecision(10)
#include <bits/stdc++.h>
constexpr int INF = 2147483647;
constexpr long long int INF_LL = 9223372036854775807;
constexpr int MOD = 1000000007;
constexpr double PI = 3.14159265358979323846;
using namespace std;
typedef long long int ll;
typedef unsigned long long int ull;

//約数列挙
vector<ll> FD(ll n) {
	vector<ll> ans;
	ans.push_back(n);
	for (ll i = 1; i * i <= n; i++) {
		if (n % i == 0) {
			ans.push_back(i);
			if (i != 1 && i * i != n)ans.push_back(n / i);
		}
	}
	return ans;
}

int main() {
	io_init;
	int N, K;
	cin >> N >> K;
	vector<ll> A(N);
	ll sum = 0;
	for (int i = 0; i < N; i++) {
		cin >> A[i];
		sum += A[i];
	}
	ll ans = 0;
	auto d = FD(sum);
	for (int i = 0; i < d.size(); i++) {
		vector<ll> B(N);
		for (int j = 0; j < N; j++) {
			B[j] = A[j] % d[i];
		}
		sort(B.begin(), B.end());
		for (int j = 0; j <= N; j++) {
			ll a = 0, b = 0;
			for (int k = 0; k < j; k++) {
				a += B[k];
			}
			for (int k = j; k < N; k++) {
				b += d[i] - B[k];
			}
			if (a == b && a <= K) {
//				cout << a << " " << d[i] << endl;
				ans = max(ans, d[i]);
			}
		}
	}
	cout << ans << endl;
}