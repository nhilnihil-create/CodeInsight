#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int inf = 1e9 + 7;
const ll longinf = 5LL << 60;
const ll mod = 1e9 + 7;

int main() {
	int N;
	cin >> N;
	int A[N];
	for(int i = 0; i < N; i++) cin >> A[i];

	double ans = 1, deno = 0;
	for(int i = 0; i < N; i++) ans *= A[i];
	for(int i = 0; i < N; i++) deno += ans / A[i];
	cout << setprecision(12) << ans / deno;

	return 0;
}