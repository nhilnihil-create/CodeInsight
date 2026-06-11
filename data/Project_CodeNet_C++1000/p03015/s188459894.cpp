#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#define debug(_) cerr << #_ << ": " << (_) << '\n'
#define _GLIBCXX_DEBUG
#else
#define debug(_) (void(0))
#endif  // LOCAL

const long long MOD = 1000000007;

int main(){
    string L;
    cin >> L;

    long long eq = 2, less = 1;

    for (int i = 1; i < L.size(); i++) {
        debug(eq), debug(less);
        if (L[i] == '1') {
            less *= 3;
            less += eq;
            less %= MOD;
            eq *= 2;
            eq %= MOD;
        } else {
            less *= 3;
            less %= MOD;
        }
    }
    debug(eq), debug(less);

    cout << ((eq + less) % MOD) << endl;

    return 0;
}