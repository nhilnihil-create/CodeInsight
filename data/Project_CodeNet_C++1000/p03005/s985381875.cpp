#include <bits/stdc++.h>

#define rep(i, n) for(int i = 0; i < (n); i++)
#define all(a) (a).begin(),(a).end()
#define SORT(a) sort(all(a))
#define rSORT(a, i) sort(all(a),(i))

using ll = long long;
constexpr ll INF = 10000000000;
constexpr ll MOD = 1000000007;
constexpr int MAX = 2000200;

using namespace std;

int main() {
	int n, k; cin >> n >> k;

	int a = n - k;

	if (k == 1) {
		cout << 0 << endl;
	}
	else {
		cout << a << endl;
	}
}


