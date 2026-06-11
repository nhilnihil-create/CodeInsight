#include <bits/stdc++.h>

#define M_PI       3.14159265358979323846   // pi

using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef vector<ll> VI;
typedef pair<ll, ll> P;
typedef tuple<ll, ll, ll> t3;
typedef tuple<ll, ll, ll, ll> t4;
typedef tuple<ll, ll, ll, ll, ll> t5;

#define rep(a,n) for(ll a = 0;a < n;a++)
#define repi(a,b,n) for(ll a = b;a < n;a++)

using namespace std;

static const ll INF = 1e15;

template<typename T>
static inline void chmin(T& ref, const T  value) {
    if (ref > value) ref = value;
}

template<typename T>
static inline void chmax(T& ref, const T value) {
    if (ref < value) ref = value;
}

constexpr ll mod = 1000000007;

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
};

void solve(int n, vector<P> ds) {
	vector<P> outputs(n);	
	rep(i, n) {
		vector<P> rs;
		ll r = ds[i].second;
		ll seed = ds[i].first;
		ll sum = 0;
		while (r > 0) {
			if (r & 1) {
				rs.emplace_back(seed, sum);
			}
			r /= 2;
			seed += seed;
			sum = sum*2+1;
			while (seed >= 10) {
				seed = seed / 10 + seed % 10;
				sum++;
			}
		}
		ll v = 0;
		ll t = 0;
		for (int j = 0; j < rs.size(); j++) {
			v += rs[j].first;
			t += rs[j].second;
			if (j > 0) t++;
			while (v >= 10) {
				v = v / 10 + v % 10;
				t++;
			}
		}
		outputs[i] = { v, t };
	}
	ll ans = 0;
	rep(i, n) {
		ans += outputs[i].second;
	}
	int current = outputs[0].first;
	rep(i, n - 1) {
		ans++;
		current += outputs[i + 1].first;
		while(current >= 10) {
			ans++;
			current = current % 10 + current / 10;
		}
	}
	cout << ans << endl;
}

void solve2(int n, vector<P> ds) {
	vector<int> values;
	for (auto p : ds) {
		for (int i = 0; i < p.second; i++) {
			values.push_back(p.first);
		}
	}
	int current = values[0];
	ll sum = 0;
	for (int i = 1; i < values.size(); i++) {
		current += values[i];
		sum++;
		while(current >= 10) {
			current = current / 10 + current % 10;
			sum++;
		}
	}
	cout << sum << endl;
}

int main() {
	int n;
	cin >> n;
	vector<P> ds(n);
	rep(i, n) {
		cin >> ds[i].first >> ds[i].second;
	}
	solve(n, ds);
	//solve2(n, ds);
	return 0;
}

