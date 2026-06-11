#include<iostream>
#include<stdio.h>
#include<string>
#include<vector>
#include<map>
#include<tuple>
#include<algorithm>
#include<cmath>
#include<limits>
#include<set>
#include<deque>
#include<queue>
using namespace std;
#define int long  long int
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
int gcd(int a, int b) { return b ? gcd(b, a % b) : a; }
int lcm(int a, int b) { return a / gcd(a, b) * b; }
typedef pair<int, int>P;
const int MOD = 1e9 + 7;
const int INF = 1e10;
const long double PI = (acos(-1));


signed main() {
	int N, K;
	cin >> N >> K;
	vector<int>A(N);
	rep(i, N)cin >> A[i];
	vector<int>v(N, 0);
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (A[i] < A[j])v[i]++;
		}
	}
	vector<int>b(N, 0);
	for (int i = 1; i < N; i++) {
		for (int j = 0; j < i; j++) {
			if (A[i] < A[j])b[i]++;
		}
	}
	int ans = 0;
	for (int i = 0; i < N; i++) {
		ans += ((K * b[i]) % MOD + (K * (K - 1) / 2) % MOD * v[i]) % MOD;
		ans %= MOD;
	}
	cout << ans;
}