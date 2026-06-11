#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
#define timer_start()                            \
    chrono::system_clock::time_point start, end; \
    start = chrono::system_clock::now();
#define timer_wrap()                                                       \
    end = chrono::system_clock::now();                                     \
    double time = static_cast<double>(                                     \
        chrono::duration_cast<chrono::microseconds>(end - start).count() / \
        1000.0);                                                           \
    printf("%lf[ms]\n", time);                                             \
    start = end;
#define optimize_cin() \
    cin.tie(0);        \
    ios::sync_with_stdio(false)
using namespace std;
using ll = long long;
#define INF 1000000000    // 10^9
#define INFINF LLONG_MAX  // 2^63-1
template <class T>
bool chmax(T &a, const T &b) {
    if (a < b) {
        a = b;
        return 1;
    }
    return 0;
}
template <class T>
bool chmin(T &a, const T &b) {
    if (b < a) {
        a = b;
        return 1;
    }
    return 0;
}
// ########## template end ##########

#ifdef DEBUG_ON
void test_all();
#endif

void resolve() {
    ll N;
    cin >> N;
    if (N % 2 == 1) {
        cout << 0 << endl;
        return;
    }
    ll ans = N / 10;
    for (ll i = 50; i <= N; i *= 5) {
        ans += N / i;
    }
    cout << ans << endl;
}

int main() {
#ifdef DEBUG_ON
    test_all();
#else
    resolve();
#endif
    return 0;
}
