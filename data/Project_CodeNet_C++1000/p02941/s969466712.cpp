#include <bits/stdc++.h>
#define loop(n, i) for(int i=0;i<n;i++)
#define loop1(n, i) for(int i=1;i<=n;i++)
#define rloop(n, i) for(int i=n;i;i++)
#define HERE cout << "HERE: " << __LINE__ << endl;
#define INSP(v) cout << v << " at " << __LINE__ << endl;
using namespace std;
using ll = long long;
template <class T>
using V = vector<T>;

int main() {
    int n; cin >> n;
    V<int> A(n), B(n);
    loop (n, i) cin >> A[i];
    loop (n, i) cin >> B[i];

    ll ans = 0;
    while (1) {
        int flg = 0;
        loop (n, i) {
            int a = (i + n - 1) % n, b = (i + 1) % n;
            ll k = (B[i] - A[i]) / (B[a] + B[b]);
            if (k <= 0) continue;
            B[i] -= k * (B[a] + B[b]);
            ans += k;
            flg = 1;
        }
        if (!flg) break;
    }
    loop (n, i) {
        if (A[i] != B[i]) {
            cout << -1 << endl;
            return 0;
        }
    }
    cout << ans << endl;
    return 0;
}

