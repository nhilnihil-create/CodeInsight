#include<bits/stdc++.h>
#define ll long long
#define rep(i,n) for(int i = 0; i < int(n); i++)
using namespace std;

template<class T> inline bool chmax(T& a, const T& b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, const T& b) { if (b < a) { a = b; return 1; } return 0; }

class modint {
	static constexpr std::int_fast64_t Modulus = 1e9 + 7;
	using u64 = std::int_fast64_t;

public:
	u64 a;
	constexpr modint(const u64 x = 0) noexcept : a(x% Modulus) {}
	constexpr u64& value() noexcept { return a; }
	constexpr const u64& value() const noexcept { return a; }
	constexpr modint operator+(const modint rhs) const noexcept {
		return modint(*this) += rhs;
	}
	constexpr modint operator-(const modint rhs) const noexcept {
		return modint(*this) -= rhs;
	}
	constexpr modint operator*(const ll rhs) const noexcept {
		return modint(*this) *= modint(rhs);
	}
	constexpr modint operator*(const modint rhs) const noexcept {
		return modint(*this) *= rhs;
	}
	constexpr modint& operator+=(const modint rhs) noexcept {
		a += rhs.a;
		if (a >= Modulus) {
			a -= Modulus;
		}
		return *this;
	}
	constexpr modint& operator-=(const modint rhs) noexcept {
		if (a < rhs.a) {
			a += Modulus;
		}
		a -= rhs.a;
		return *this;
	}
	constexpr modint& operator*=(const modint rhs) noexcept {
		a = a * rhs.a % Modulus;
		return *this;
	}
	constexpr operator u64() const { return a; }
};

int main() {
	string L;
	cin >> L;
	int n = L.size();
	vector<vector<modint>> dp(n + 1, vector<modint>(2, 0));
	//dp[i][1]...a+bが等しい
	//dp[i][0]...a+bが小さい
	dp[0][1] = 2;//10,01
	dp[0][0] = 1;//00
	for (int i = 1; i < n; i++) {
		const bool one = L[i] == '1';
		if (one) {
			dp[i][1] += dp[i - 1][1] * 2LL;//10,01
			dp[i][0] += dp[i - 1][0] * 3LL;//10,01,00
			dp[i][0] += dp[i - 1][1] * 1LL;//00
		}
		else {
			dp[i][1] += dp[i - 1][1] * 1LL;//00
			dp[i][0] += dp[i - 1][0] * 3LL;//10,01,00
		}
	}
	ll sum = dp[n - 1][0] + dp[n - 1][1];
	cout << sum << endl;
	return 0;
}
