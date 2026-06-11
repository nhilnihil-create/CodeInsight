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
#include "functional"
#include "ctime"

using namespace std;

//constexpr long long int MOD = 1000000007;
//constexpr int MOD = 1000000007;
constexpr int MOD = 998244353;
//constexpr long long int MOD = 998244353;
constexpr double EPS = 1e-8;

//int N, M, K, H, W, L, R;
long long int N, M, K, H, W, L, R;



int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	cin >> N;
	vector<long long int>v(N);
	long long int x = 0;
	for (auto &i : v) {
		cin >> i;
		x ^= i;
	}
	long long int add = 0;
	for (int i = 0; i < 59; i++) {
		if ((x >> i) & 1) {
			add += 1LL << i;
			x ^= 1LL << i;
			for (auto &j : v)if ((j >> i) & 1)j ^= 1LL << i;
		}
	}
	for (int i = 59; i >= 0; i--) {
		for (int j = 0; j < N; j++) {
			if ((v[j] >> i) & 1) {
				bool flag = false;
				for (int k = i + 1; k < 60; k++) {
					if ((v[j] >> k) & 1)flag = true;
				}
				if (flag)continue;
				for (int k = 0; k < N; k++) {
					if (j == k)continue;
					if ((v[k] >> i) & 1)v[k] ^= v[j];
				}
				break;
			}
		}
	}
	sort(v.begin(), v.end());
	reverse(v.begin(), v.end());
	//for (auto i : v)cout << i << endl;
	long long int  y = 0;
	for (auto i : v) y ^= i;
	x ^= y;
	//cout << x << " " << y << endl;
	//for (int i = 59; i >= 0; i--) {
	//	if ((x >> i) & 1)y ^= box[i];
	//	else x ^= box[i];
	//	cout << x << " " << y << endl;
	//}
	cout << x + y + add << endl;
}