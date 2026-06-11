#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef vector<long long> vll;
typedef pair<long long, long long> pll;

const ll INF = 1e15;
const ll MOD = 1e9 + 7;

int main() {
    ll i, j, k;
    ll N;
    cin >> N;
    vll A(N), B(N);
    for(auto &e : A)
        cin >> e;
    for(auto &e : B)
        cin >> e;
    ll ok = false;
    ll update = false;
    ll ans = 0;
    while(!ok) {
        update = false;
        for(i = 0; i < N; i++) {
            ll le = i - 1;
            if(le < 0)
                le = N - 1;
            ll ri = i + 1;
            if(ri >= N)
                ri = 0;
            if(B[i] > A[i] && B[i] > (B[le] + B[ri])) {
                ll m = (B[i] - A[i]) / (B[le] + B[ri]);
                ans += m;
                if(m > 0)
                    update = true;
                B[i] -= m * (B[le] + B[ri]);
            }
        }
        if(update)
            continue;
        for(i = 0; i < N; i++) {
            if(A[i] != B[i]) {
                cout << -1 << endl;
                return 0;
            }
        }
        ok = true;
    }
    cout << ans << endl;

    return 0;
}
