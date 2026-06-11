
#include <bits/stdc++.h>

#define M_PI       3.14159265358979323846   // pi

using namespace std;
typedef long long ll;
typedef pair<ll, ll> P;
typedef tuple<ll, ll, ll> t3;

#define rep(a,n) for(ll a = 0;a < n;a++)

static const ll INF = 1e15;
static const ll mod = 1e9+7;

template<typename T>
static inline void chmin(T& ref, const T  value) {
    if (ref > value) ref = value;
}

template<typename T>
static inline void chmax(T& ref, const T value) {
    if (ref < value) ref = value;
}

struct RollingHash {
	typedef long long int_type;
	typedef pair<int_type, int_type> hash_type;

	int_type base1;
	int_type base2;
	int_type mod1;
	int_type mod2;

	vector<int_type> hash1;
	vector<int_type> hash2;
	vector<int_type> pow1;
	vector<int_type> pow2;

	RollingHash(const string& s) : base1(1009), base2(1007), mod1(1000000007), mod2(1000000009) {
		init(s);
	}

	void init(const string& s) {
		int n = s.size();
		hash1.assign(n + 1, 0);
		hash2.assign(n + 1, 0);
		pow1.assign(n + 1, 1);
		pow2.assign(n + 1, 1);
		for (int i = 0; i < n; i++) {
			hash1[i + 1] = (hash1[i] + s[i]) * base1 % mod1;
			hash2[i + 1] = (hash2[i] + s[i]) * base2 % mod2;
			pow1[i + 1] = pow1[i] * base1 % mod1;
			pow2[i + 1] = pow2[i] * base2 % mod2;
		}
	}

	hash_type get(int l, int r) const {
		int_type t1 = ((hash1[r] - hash1[l] * pow1[r - l]) % mod1 + mod1) % mod1;
		int_type t2 = ((hash2[r] - hash2[l] * pow2[r - l]) % mod2 + mod2) % mod2;
		return make_pair(t1, t2);
	}

	RollingHash::hash_type concat(hash_type h1, hash_type h2, int h2_len) {
		return make_pair((h1.first * pow1[h2_len] + h2.first) % mod1,
			(h1.second * pow2[h2_len] + h2.second) % mod2);
	}

	int LCP(const RollingHash& other, int l1, int r1, int l2, int r2) {
		int len = min(r1 - l1, r2 - l2);
		int low = -1, high = len + 1;
		while (high - low > 1) {
			int mid = (low + high) / 2;
			if (get(l1, l1 + mid) == other.get(l2, l2 + mid)) low = mid;
			else high = mid;
		}
		return (low);
	}
};

std::vector<int> z_algorithm(string text) {
	int n = text.size();
	vector<int> A(n, 0);
	A[0] = text.size();
	int i = 1, j = 0;
	while (i < text.size()) {
		while (i + j < text.size() && text[j] == text[i + j]) ++j;
		A[i] = j;
		if (j == 0) { ++i; continue; }
		int k = 1;
		while (i + k < text.size() && k + A[k] < j) A[i + k] = A[k], ++k;
		i += k; j -= k;
	}
	return A;
}

int main() {
	ll n;
	cin >> n;
	string s;
	cin >> s;
	n = s.size();
	int u = 0;
	for (int i = 0; i < n; i++) {
		auto t = s.substr(i, n - i);
		auto a = z_algorithm(t);
		for (int j = i + 1; j < n; j++) {
			auto num = min(a[j - i], j - i);
			chmax(u, num);
		}
	}
	cout << u << endl;
	return 0;
}
