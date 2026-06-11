#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
#define int ll

#define REP(i,n) for(int i=0;i<n;++i)
#define ALL(name) name.begin(),name.end()
#define SORT(name) sort(name.begin(), name.end())
#define ZERO(p) memset(p, 0, sizeof(p))
#define MINUS(p) memset(p, -1, sizeof(p))
#if 1
#  define DBG(fmt, ...) printf(fmt, ##__VA_ARGS__)
#else
#  define DBG(fmt, ...)
#endif

const ll LLINF = (1LL<<60);
const int INF = (1LL<<30);
const double DINF = std::numeric_limits<double>::infinity();
const int MOD = 1000000007;
#define MAX_N 100010
#define SUBMIT

ll T1, T2, A1, A2, B1, B2;

ll brute_force() {
    const ll border = 100000000000000000LL;
    ll cur_a = A1 * T1;
    ll cur_b = B1 * T1;
    ll prev_a = cur_a;
    ll prev_b = cur_b;
    ll ret = (cur_a == cur_b) ? 1 : 0;
    ll turn = 0;
    while(1) {
        if(turn % 2 ==0) {
            cur_a += A2 * T2;
            cur_b += B2 * T2;
            if(cur_a == cur_b) { return -1; }
        }
        else {
            cur_a += A1 * T1;
            cur_b += B1 * T1;
        }
        if(prev_a > prev_b) {
            if(cur_a <= cur_b) { ret++; }
            else { break; }
        }
        if(prev_a < prev_b) {
            if(cur_a >= cur_b) { ret++; }
            else { break; }
        }
        turn++;
        if(cur_a > border) {
            cur_a -= border;
            cur_b -= border;
        }
        prev_a = cur_a;
        prev_b = cur_b;
    }
    return ret;
}

ll solve() {
    ll a1 = T1 * A1;
    ll b1 = T1 * B1;
    ll a2 = T2 * A2;
    ll b2 = T2 * B2;

    ll X = a1 - b1;
    ll Y = a2 - b2;


    if(X + Y == 0) {
        return -1;
    }

    if((X < 0 && Y < 0) || (X > 0 && Y > 0) || Y == 0) {
        return 0;
    }

    if(X == 0) {
        return 1;
    }

    X = abs(X);
    Y = abs(Y);
    if(X > Y) {
        //swap(X, Y);
        return 0;
    }

    ll ret = X / (Y - X) * 2 + 1;
    if(X % (Y - X) == 0) {
        ret = X / (Y - X) * 2;
    }
    return ret;
}

signed main() {
    cin.tie(0); cout.tie(0);
    ios::sync_with_stdio(false);
#ifdef SUBMIT
    cin >> T1 >> T2 >> A1 >> A2 >> B1 >> B2;
    ll ans = solve();
    //ll ans = brute_force();
    if(ans == -1) {
        printf("infinity\n");
        return 0;
    }
    printf("%lld\n", ans);
#else
    for(T1 = 1; T1 < 10; ++T1) {
        for(T2 = 1; T2 < 10; ++T2) {
            for(A1 = 1; A1 < 10; ++A1) {
                for(A2 = 1; A2 < 10; ++A2) {
                    for(B1 = 1; B1 < 10; ++B1) {
                        for(B2 = 1; B2 < 10; ++B2) {
                            ll ans = brute_force();
                            ll cand = solve();
                            if(ans != cand) {
                                printf("%lld %lld\n", T1, T2);
                                printf("%lld %lld\n", A1, A2);
                                printf("%lld %lld\n", B1, B2);
                                printf("ans: %lld cand: %lld\n", ans, cand);
                                return 0;
                            }
                        }
                    }
                }
            }
        }
    }
#endif
    return 0;
}
