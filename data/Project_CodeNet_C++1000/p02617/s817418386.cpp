#include <bits/stdc++.h>
using namespace std;
using ll = long long;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
#define rep(i, start, n) for (int i = (int)(start); i < (int)(n); ++i)
#define all(a) a.begin(), a.end()
#define mp(a, b) make_pair(a, b)

int INF = 100100100;
const int MAX = 110000;
const int MOD = 1000000007;

int main(){
    ll N;
    cin >> N;
    ll ans = N*(N*N+N*3+2)/6;
    rep(i, 0, N-1){
        ll u, v;
        cin >> u >> v;
        if (u > v) swap(u, v);
        ans -= u*(N-v+1);
    }
    cout << ans << endl;
}