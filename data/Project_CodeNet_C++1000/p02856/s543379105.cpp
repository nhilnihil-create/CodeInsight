#include <bits/stdc++.h>
#define MOD 1000000007
#define INF 1001001001
#define LINF 1001001001001001001
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define bit(n) (1LL<<(n))
using namespace std;

typedef long long ll;
typedef pair<int, int> P;
typedef pair<ll, ll> LLP;

int main() {

    int M;
    cin >> M;
    vector<ll> d(M), c(M);
    rep(i,M) cin >> d[i] >> c[i];

    ll N = 0;
    ll digitsum = 0;
    rep(i,M) {
        N += c[i];
        digitsum += d[i] * c[i];
    }

    ll ans = N - 1 + (digitsum - 1) / 9;
    cout << ans << endl;
    
    return 0;
}