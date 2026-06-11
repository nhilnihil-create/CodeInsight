#include <bits/stdc++.h>
using namespace std;

#define rep(i, n) for(int i = 0; i < (n); ++i)

typedef long long ll;
typedef pair<int, int> P;

const int MAX = 1e5 + 5;
const int INF = 1001001001;
const int MOD = 1e9 + 7;

int main(){
    int N;
    cin >> N;

    vector<ll> A(N);
    rep(i, N) cin >> A[i];

    ll U = 0;
    rep(i, N) U ^= A[i];

    int cnt = 0;
    for (int i = 60; i >= 0; --i) {
        if (U >> i & 1) continue;

        bool find = false;
        for (int j = cnt; j < N; j++) {
            if (A[j] >> i & 1) {
                swap(A[cnt], A[j]);
                cnt++;
                find = true;
                break;
            }
        }

        if (find) {
            rep(j, N) {
                if (j == cnt - 1) continue;
                if (A[j] >> i & 1) A[j] ^= A[cnt - 1];
            }
        }
    }

    ll ans = 0, res = 0;
    rep(i, N - 1) {
        res ^= A[i];
        ans = max(ans, res + (U ^ res));
    }

    cout << ans << endl;
}