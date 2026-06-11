#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using P = pair<int, int>;

/* 繰り返し自乗法. */
int modPow(long long a, long long n, long long p) {
	if (n == 0) return 1; // 0乗にも対応する場合.
	if (n == 1) return a % p;
	if (n % 2 == 1) return (a * modPow(a, n - 1, p)) % p;
	long long t = modPow(a, n / 2, p);
	return (t * t) % p;
}

signed main() {
 //   cout << "aaa" << endl;
    int N;
    cin >> N;
    vector<int> A(N);
    rep (i, N) {
        int a;
        cin >> A[i];
    }
    sort(A.begin(), A.end());
    bool ret = true;
    rep (i, N-1) {
        if (A[i] == A[i+1]) {
            ret = false;
            break;
        }
    }

    if (ret == true) cout << "YES" << endl;
    else            cout << "NO"  << endl;

}