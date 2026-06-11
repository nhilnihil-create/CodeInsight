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
    ll ans = 0;
    for(ll i = 2; i * i <= N; i++) {
        if(N % i != 0) continue;
        ll num = 0;
        while(N % i == 0) {
            N /= i;
            num++;
        }
        for(ll j = 1; ; j++) {
            if(num >= j) {
                num -= j;
                ans++;
            } else break;
        }
    }
    if(N != 1) ans++;
    cout << ans << endl;
    return 0;
}
