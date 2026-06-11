#include<bits/stdc++.h>
using namespace std;
using uint = unsigned int;
using ll = long long;
using ull = unsigned long long;

#define FOR(i,a,b) for (int i = a; i < b; ++i)
#define FORR(i,a,b) for (int i = b - 1; i >= a; --i)
#define REP(i,n) FOR(i,0,n)
#define REPR(i,n) FORR(i,0,n)

int main() {
	ll A, B, N;
	ll maxval = numeric_limits<ll>::min(), val;
	cin >> A >> B >> N;

	if (B <= N) {
		val = (A * (B - 1)) / B;
	}
	else {
		val = ((A * N) / B) - (A * (N / B));
	}
	cout << val << endl;
	/*
	for (ll x = B - 1; x <= N; x += B) {
		val = ((A * x) / B) - (A * (x / B));
		maxval = max(maxval, val);
	}

	val = ((A * N) / B) - (A * (N / B));
	maxval = max(maxval, val);

	cout << maxval << endl;
	*/
	return 0;
}