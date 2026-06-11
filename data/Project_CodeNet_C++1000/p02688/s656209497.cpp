#include <bits/stdc++.h>
using namespace std;

#define loop(i, a, b) for (int i = (a); i < (b); ++i)
#define rep(i, n) for (int i = 0; i < n; ++i)
#define dump(a) cerr << #a << " = " << (a) << "(L:" << __LINE__ << ")" << endl

int main() {
    int N, K;
    cin >> N >> K;
    vector<int> C(N);
    rep(i, K) {
        int d;
        cin >> d;
        rep(j, d) {
            int a;
            cin >> a;
            a--;
            C[a]++;
        }
    }

    int ans = 0;
    rep(i, N) {
        if (C[i] == 0) {
            ans++;
        }
    }
    cout << ans << endl;
    return 0;
}
