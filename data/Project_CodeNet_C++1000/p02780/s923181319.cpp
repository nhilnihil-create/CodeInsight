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

using namespace std;
using ll = long long;

template<typename T> void print(T t) { cout << t << endl; }

int main() {
	int N, K, p;
	cin >> N >> K;
	vector<ll> kitai2(N);
	for (int i = 0; i < N; i++) {
		cin >> p;
		kitai2[i] = 1ll + p;
	}
	ll k=0, kmax;
	for (int i = 0; i < K; i++) {
		k += kitai2[i];
	}
	kmax = k;

	for (int i = K; i < N; i++) {
		k += kitai2[i] - kitai2[i-K];
		kmax = max(kmax, k);
	}
	cout << fixed << setprecision(12) << kmax * 0.5 << endl;

}