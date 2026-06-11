#include <bits/stdc++.h>
#define endl "\n"
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

const long long INF = 1e18;
//const ll mod = 1000000007;

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll N;
    cin >> N;
    bool a = false;
    ll ans = 1;
    while(N--) {
        ll b;
        cin >> b;
        if(b == 0) {
            cout << 0 << endl;
            return 0;
        }
        if(INF / b < ans) a = true;
        ans *= b;
    }
    if(a) ans = -1;
    if(ans > INF) ans = -1;
    cout << ans << endl;
    return 0;
}
