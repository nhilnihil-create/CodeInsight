#include "iostream"
#include "climits"
#include "list"
#include "queue"
#include "stack"
#include "set"
#include "functional"
#include "algorithm"
#include "string"
#include "map"
#include "unordered_map"
#include "unordered_set"
#include "iomanip"
#include "cmath"
#include "random"
#include "bitset"
#include "cstdio"
#include "numeric"
#include "cassert"
#include "ctime"

using namespace std;

constexpr long long int MOD = 1000000007;
//constexpr int MOD = 1000000007;
//constexpr int MOD = 998244353;
//constexpr long long int MOD = 998244353;
constexpr long double EPS = 1e-12;

//int N, M, K, H, W, L, R;
long long int N, M, K, H, W, L, R;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	cin >> N >> K;
	vector<long long int>v(N);
	for (auto &i : v)cin >> i;
	while (K--) {
		cin >> M >> L >> R;
		long long int ed = L;
		auto w = v;
		long long int sum = 0;
		for (auto &i : w) {
			i %= R;
			sum += i;
		}
		long long int index = 0;
		for (; index%N != (M - 1) % N; index++) {
			ed += w[index];
		}
		ed += (M - 1 - index) / N*sum;
		long long int ans = M - 1;
		ans -= ed / R - L / R;
		for (int i = 0; i < N; i++) {
			if (!w[i]) {
				ans -= (M - 1) / N;
				if ((M - 1) % N > i)ans--;
			}
		}
		cout << ans << endl;
	}
	return 0;
}