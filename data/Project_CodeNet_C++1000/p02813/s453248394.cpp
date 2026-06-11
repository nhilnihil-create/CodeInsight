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
constexpr double EPS = 1e-8;

//int N, M, K, H, W, L, R;
long long int N, M, K, H, W, L, R;



int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	cin >> N;
	vector<int>v(N);
	vector<int>w(N);
	for (auto &i : v)cin >> i;
	for (auto &i : w)cin >> i;
	vector<int>p(N);
	int a = 0, b = 0;
	for (int i = 0; i < N; i++)p[i] = i + 1;
	int cnt = 0;
	do {
		if (p == v)a = cnt;
		if (p == w)b = cnt;
		cnt++;
	} while (next_permutation(p.begin(), p.end()));
	cout << abs(a - b) << endl;

}
