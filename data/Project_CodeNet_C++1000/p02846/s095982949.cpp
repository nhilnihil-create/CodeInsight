#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> l_l;
typedef pair<int, int> i_i;
template<class T>
inline bool chmax(T &a, T b) {
    if(a < b) {
        a = b;
        return true;
    }
    return false;
}

template<class T>
inline bool chmin(T &a, T b) {
    if(a > b) {
        a = b;
        return true;
    }
    return false;
}

#define EPS (1e-7)
#define INF (1e9)
#define PI (acos(-1))
//const ll mod = 1000000007;
ll T[2];
ll C[2];
ll A[2];
ll B[2];

int main() {
    //cout.precision(10);
    cin.tie(0);
    ios::sync_with_stdio(false);
    for(int i = 0; i <= 1; i++) cin >> T[i];
    for(int i = 0; i <= 1; i++) cin >> A[i];
    for(int i = 0; i <= 1; i++) cin >> B[i];
    for(int i = 0; i <= 1; i++) C[i] = (A[i] - B[i]) * T[i];
    if(C[0] < 0) {
        C[0] *= -1;
        C[1] *= -1;
    }
    if(C[1] > 0) {
        cout << 0 << endl;
        return 0;
    }
    if(-C[1] < C[0]) {
        cout << 0 << endl;
        return 0;
    }
    if(-C[1] == C[0]) {
        cout << "infinity" << endl;
        return 0;
    }
    ll delta = +C[1] + C[0];
    ll ans = 0;
    ans = 2 * (C[1] / delta) - 1;
    if(C[1] % delta == 0) ans--;
    cout << ans << endl;
    cerr << C[0] << " " << C[1] << " " << delta << endl;
    //cout << C[1] / delta << endl;
    return 0;
}
