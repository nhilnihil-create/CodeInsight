#include <bits/stdc++.h>

#define debug(x) cerr << #x << ": " << x << endl
#define debugArray(x, n)                                                       \
    for(long long hoge = 0; (hoge) < (n); ++(hoge))                            \
    cerr << #x << "[" << hoge << "]: " << x[hoge] << endl
using namespace std;

using ll = long long;
using ull = unsigned long long;
const ll INF = LLONG_MAX / 2;
const ll MOD = 1e9 + 7;

signed main() {
    cin.tie(0);
    ios::sync_with_stdio(0);
    ll N, K;
    cin >> N >> K;
    ll A[N], F[N];
    for(int i = 0; i < N; i++) {
        cin >> A[i];
    }
    sort(A, A + N);
    for(int i = 0; i < N; i++) {
        cin >> F[i];
    }
    sort(F, F + N);
    ll low = -1, high = INF;
    while(high - low > 1) {
        ll mid = (high + low) / 2;
        ll k = K;
        bool isok = true;
        for(int i = 0; i < N; i++) {
            if(A[i] * F[N - i - 1] <= mid) {
                continue;
            }
            ll a = mid / F[N - i - 1];
            ll sub = A[i] - a;
            if(sub > k) {
                isok = false;
                break;
            }
            k -= sub;
        }
        if(isok) {
            high = mid;
        } else {
            low = mid;
        }
    }
    cout << high << endl;
    return 0;
}