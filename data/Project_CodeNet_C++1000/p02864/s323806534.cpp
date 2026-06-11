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
ll N, K;
ll H[305];
ll Prev[305][305], Next[305][305];

int main() {
    //cout.precision(10);
    cin.tie(0);
    ios::sync_with_stdio(false);
    cin >> N >> K;
    for(int i = 1; i <= N; i++) {
        cin >> H[i];
    }
    for(int i = 1; i <= N; i++) {
        for(int j = 0; j <= N; j++) {
            for(int timer = 0; timer <= K; timer++) {
                Next[j][timer] = 1e18;
            }
        }
        for(int timer = 0; timer <= K; timer++) {
            for(int j = 0; j < i; j++) {
                chmin(Next[i][timer], Prev[j][timer] + max(0LL, H[i] - H[j]));
                if(timer > 0) {
                    chmin(Next[j][timer], Prev[j][timer-1]);
                }
            }
        }
        swap(Prev, Next);
        for(int j = 0; j <= i; j++) {
            for(int k = 0; k <= K; k++) {
                //cerr << i << " " << j << " " << k << " " << Prev[j][k] << endl;
            }
        }
    }
    ll ans = 1e18;
    for(int i = 0; i <= N; i++) {
        for(int j = 0; j <= K; j++) {
            chmin(ans, Prev[i][j]);
        }
    }
    cout << ans << endl;
    return 0;
}
