#include <bits/stdc++.h>
using namespace std;

#define rep(i, n) for(int i = 0; i < (n); ++i)
#define repr(i, n) for(int i = (n-1); i >= 0; --i)

template<class T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return 1; } return 0; }

typedef long long ll;
typedef pair<int, int> P;

const int MAX = 200005;
const int INF = 1001001001;
const int MOD = 1000000007;

int main(){
    int N;
    cin >> N;

    ll ans = 0;
    for (int i = 1; i <= N; ++i) ans += (ll)i * (N-i+1);

    rep(i, N-1) {
        int v, u;
        cin >> v >> u;
        if (v > u) swap(v, u);
        ans -= (ll)v * (N-u+1);
    }

    cout << ans << endl;
}