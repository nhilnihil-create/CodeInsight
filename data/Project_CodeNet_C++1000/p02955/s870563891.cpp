#include <bits/stdc++.h>
#include <vector>
#include <iostream>
#include<algorithm>
#include<string>
#include <map>
#include <queue>
#include <stack>
#include<set>
#include<tuple>

#define DIV 1000000007
using namespace std;
using ll = long long;
using ldb = long double;

ll pm(vector<ll>& a, ll M, ll K) {
	int N = a.size();
	vector<ll> b(N);
	ll srm = 0;
	for (int i = 0; i < N; i++) {
		b[i] = a[i] % M;
		srm += b[i];
	}

	sort(b.begin(), b.end(), greater<ll>());
	ll inc = 0;
	for (int i = 0; i < srm / M; i++) {
		inc += (M - b[i]);
	}

	if (inc <= K)return M;
	else return 0;
}

int main() {
	ll N, K; cin >> N >> K;
	vector<ll> a(N);
	ll sum = 0;
	for (int i = 0; i < N; i++) {
		cin >> a[i];
		sum += a[i];
	}

	ll d = 1;
	for (ll i = 2; i <= sqrt(sum); i++) {
		if (sum % i == 0) {
			d = max(d, pm(a, i, K));
			d = max(d, pm(a, sum / i, K));
		}
	}

	if (sum >= 2) d = max(d, pm(a, sum, K));
	cout << d << endl;
}
