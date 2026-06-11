#include <iostream>
#include <cstdio>
#include <algorithm>
#include <string>
#include <stack>
#include <queue>
#include <vector>
#include <list>
#include <set>
#include <map>
#include <cmath>

using namespace std;
#define PI 3.1415926535897932384626433832795
#define MOD (1000000007)
#define EPS (1e-15)
#define rep(i, n) for (int i = 0; i < (n); i++)
#define repc(i, s, n) for (int i = (s); i <= (n); i++)
#define rrep(i, n) for (int i = (n) - 1; i >= 0; i--)
#define rrepc(i, s, n) for (int i = (s); i >= (n); i--)
#define bet(x, a, b) (a) <= (x) && (x) < (b)
typedef long long ll;
typedef unsigned long long ull;

int A[2000];

int main()
{
	int N;
	ll K, ans = 0;

	cin >> N >> K;
	rep(i, N) cin >> A[i];

	rep(i, N) {
		rep(j, N) {
			if (j < i) {
				if (A[i] > A[j]) {
					ans = (ans + (K - 1) * K / 2) % MOD;
				}
			}
			else if (i < j) {
				if (A[i] > A[j]) {
					ans = (ans + K * (K + 1) / 2) % MOD;
				}
			}
		}
	}

	cout << ans << endl;

	return 0;
}
