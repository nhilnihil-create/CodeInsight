#include <iostream>
#include <string>
#include <functional>
#include <algorithm>
#include <set>
#include <map>
#include <unordered_map>
#include <cmath>
#include <cstdio>


using namespace std;

typedef long long ll;

#define FOR(i, a, b) for (int i = (a); i < (b); ++i)
#define REP(i, n) for (int i = 0; i < (n); ++i)

int main(int argc, char **argv)
{
    ll N;
    ll K;
    cin >> N >> K;
    ll A[N], F[N];
    REP(i, N) cin >> A[i];
    REP(i, N) cin >> F[i];

    sort(A, A + N);
    sort(F, F + N, greater<int>());
    ll start, end;
    start = 0;
    end = 1e+14;
    ll target = (end + start) / 2;
    while (start != target) {
        ll resK = K;
        bool f = true;
        REP(i, N) {
            if (A[i] * F[i] > target) {
                ll x = A[i] - target / F[i];
                if (resK < x) {
                    f = false;
                    break;
                }
                else {
                    resK -= x;
                }
            }
        }
        if (f) end = target;
        else start = target;
        target = (end + start) / 2;
    }
    ll resK = K;
    bool f = true;
    REP(i, N) {
        if (A[i] * F[i] > target) {
            ll x = A[i] - target / F[i];
            if (resK < x) {
                f = false;
                break;
            }
            else {
                resK -= x;
            }
        }
    }
    if (f) cout << target << endl;
    else cout << target + 1 << endl;

    return 0;
}
