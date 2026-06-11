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
    int M;
    cin >> M;

    vector<int> d(M);
    vector<ll> c(M);
    rep(i, M) cin >> d[i] >> c[i];

    ll D = accumulate(c.begin(), c.end(), 0L);
    ll sum = 0;
    rep(i, M) sum += d[i] * c[i];

    ll ans = (D - 1) + (sum - 1) / 9;
    cout << ans << endl;
}