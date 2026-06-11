#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
using namespace std;
#define rep(i, a, b) for(long long i = a; i < (b); ++i)
typedef long long ll;

int main() {
    ll N, K, R, S, P;
    cin >> N >> K >> R >> S >> P;
    string T;
    cin >> T;
     
    vector<bool>U(N,false);
    ll ans = 0;
    rep(i, 0, N) {
        ll p = i - K;
        if (p >= 0 && T[i] == T[p] && U[p])
            continue;
        U[i] = true;
        if (T[i] == 'r')
            ans += P;
        else if (T[i] == 's')
            ans += R;
        else
            ans += S;
    }
    cout << ans << endl;
    return 0;
}
