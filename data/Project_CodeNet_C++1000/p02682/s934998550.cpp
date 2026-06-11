#include<bits/stdc++.h>
using namespace std;
using uint = unsigned int;
using ll = long long;
using ull = unsigned long long;

#define FOR(i,a,b) for (int i = a; i < b; ++i)
#define FORR(i,a,b) for (int i = b - 1; i >= a; --i)
#define REP(i,n) FOR(i,0,n)
#define REPR(i,n) FORR(i,0,n)

//#define DEBUG_MODE

int main() {
        ll A, B, C, K;
        cin >> A >> B >> C >> K;

        ll ans = 0;

        // A (1)
        if (K <= A) {
                ans = K;
                K = 0;
        } else {
                ans = A;
                K -= A;
        }

#ifdef DEBUG_MODE
        cout << "K: " << K << ", ans: " << ans << endl;
#endif

        // B (0)
        K -= B;

#ifdef DEBUG_MODE
        cout << "K: " << K << ", ans: " << ans << endl;
#endif

        // C (-1)
        if (K > 0) ans -= K;

#ifdef DEBUG_MODE
        cout << "K: " << K << ", ans: " << ans << endl;
#endif

        cout << ans << endl;

        return 0;
}
