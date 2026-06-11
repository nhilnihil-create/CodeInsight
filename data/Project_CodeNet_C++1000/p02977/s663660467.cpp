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

using namespace std;

//const long long int MOD = 1000000007;
const int MOD = 1000000007;
//const int MOD = 998244353;
//const long long int MOD = 998244353;
const double EPS = 1e-8;

int N, M, K, H, W, L, R;
//long long int N, M, K, H, W, L, R;


int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	cin >> N;
	int box = 1;
	while (box < N)box <<= 1;
	if (box == N) {
		cout << "No\n";
		return 0;
	}
	cout << "Yes\n";
	cout << 1 << " " << 2 << endl;
	cout << 2 << " " << 3 << endl;
	cout << 3 << " " << N + 1 << endl;
	cout << N + 1 << " " << N + 2 << endl;
	cout << N + 2 << " " << N + 3 << endl;
	for (int i = 4; i <= N - 1; i += 2) {
		cout << 1 << " " << i << endl;
		cout << i << " " << i + 1 << endl;
		cout << 1 << " " << N + i + 1 << endl;
		cout << N + i + 1 << " " << N + i << endl;
	}
	if (N % 2 == 0) {
		for (int i = 2; i < N; i += 2) {
			int box = N ^ 1 ^ i;
			if (box < N) {
				cout << i << " " << N << endl;
				cout << box + N << " " << 2 * N << endl;
				return 0;
			}
		}
	}
}