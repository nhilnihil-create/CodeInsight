#include <iostream>
#include <cmath>
#include <climits>
#include <string>
#include <numeric>
#include <vector>
#include <queue>
#include <map>
#include <algorithm>
#include <functional>
#include <iomanip>
#include <set>

using namespace std;
using ll = long long;

template<typename T> void print(T t) { cout << t << endl; }
ll MOD = 1000000007;

int main() {
	int N, K;
	cin >> N >> K;
	vector<ll> A(N), Ten(N, 0), Rank(N, 0);
	for (auto& a : A) cin >> a;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (A[j] > A[i]) {
				if(j<i)Ten[i]++;
				Rank[i]++;
			}
		}
	}

	ll ans = 0;
	for (int i = 0; i < N; i++) {
		ans += Ten[i]*K;
		ans %= MOD;
		ans += Rank[i] * ((K * (K -1ll)/2) % MOD);
		ans %= MOD;
	}
	print(ans);


}
