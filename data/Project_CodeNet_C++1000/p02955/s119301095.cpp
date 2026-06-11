#pragma once

#include <bits/stdc++.h>

#define M_PI       3.14159265358979323846   // pi

using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef vector<int> VI;
typedef pair<ll, ll> P;
typedef tuple<ll, ll, ll> t3;

#define rep(a,n) for(int a = 0;a < n;a++)
#define repi(a,b,n) for(int a = b;a < n;a++)

const ull mod = 1000000007;

class Primes {
private:
	vector<int> Prime_Number;
	vector<bool> is_prime_;
public:
	Primes(int N) {
		is_prime_.resize(N + 1, true);
		is_prime_[0] = is_prime_[1] = false;
		for (int i = 0; i < N + 1; i++) {
			if (is_prime_[i]) {
				Prime_Number.push_back(i);
				for (int j = 2 * i; j <= N; j += i) is_prime_[j] = false;
			}
		}
	}
	int operator[](int i) { return Prime_Number[i]; }
	int size() { return Prime_Number.size(); }
	int back() { return Prime_Number.back(); }
	bool isPrime(int q) { return is_prime_[q]; }
};

class Divisor {
private:
	vector<ll> F;
	vector<pair<ll, ll>> pfactorize;
public:
	Divisor(ll N) {
		for (ll i = 1; i * i <= N; i++) {
			if (N % i == 0) {
				F.push_back(i);
				if (i * i != N) F.push_back(N / i);
			}
		}
		sort(begin(F), end(F));
		Primes p((ll)sqrt(N) + 1);
		for (int i = 0; i < p.size(); i++) {
			pfactorize.emplace_back(p[i], 0);
			while (N % p[i] == 0) {
				N /= p[i];
				pfactorize.back().second++;
			}
			if (pfactorize.back().second == 0) pfactorize.pop_back();
		}
		if (N > 1) pfactorize.emplace_back(N, 1);
	}
	int size() { return F.size(); }
	const vector<pair<ll, ll>>& pfac() { return pfactorize; } const
	ll operator[](int k) { return F[k]; }
};

int main(void)
{
	ll n, k;
	cin >> n >> k;
	vector<ll> vs(n);
	rep(i, n) cin >> vs[i];
	ll sum = 0;
	rep(i, n) sum += vs[i];
	Divisor d(sum);
	ll minValue = 1;
	vector<ll> buf(n);
	rep(a, d.size()) {
		ll div = d[a];
		rep(i, n) {
			buf[i] = vs[i] % div;
		}
		sort(buf.begin(), buf.end());
		
		vector<long> p(n + 1);
		vector<long> q(n + 1);
		for (int i = 0; i < n; ++i) p[i + 1] = p[i] + buf[i];
		for (int i = n; i > 0; --i) q[i - 1] = q[i] + div - buf[i - 1];
		for (int i = 0; i <= buf.size(); ++i) {
			if (p[i] == q[i]) {
				int ans = p[i];
				if (ans <= k) {
					minValue = max(minValue, div);
					break;
				}
			}
		}		
	}
	cout << minValue << endl;
	return 0;
}
