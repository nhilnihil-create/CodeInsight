#include <bits/stdc++.h>
using namespace std;
#define repd(i,a,b) for (int i=(a);i<(b);i++)
#define rep(i,n) repd(i,0,n)
#define all(x) (x).begin(),(x).end()
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }
typedef long long ll;
const long long INF = 1LL << 60;
const long long MOD = 1e9 + 7;
typedef pair<int, int> P;
int main()
{
    ll N, K;
    cin >> N >> K;
    vector<int> A(N);
    rep(i, N) cin >> A[i];

    ll ans = 0;
    ll ct = ((K - 1) * K) / 2;
    ct %= MOD;
    rep(i, N) {
        ll cnt = 0;
        repd(j, i + 1, N) {
            if (A[i] > A[j]) cnt++;
        }
        ans += cnt * K;
        ans %= MOD;
        cnt = 0;
        rep(j, N) {
            if (A[i] > A[j]) cnt++;
        }
        ans += cnt * ct;
        ans %= MOD;
    }

    cout << ans % MOD << endl;
    return 0;
}