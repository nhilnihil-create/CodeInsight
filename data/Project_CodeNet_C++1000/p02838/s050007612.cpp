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
    ll N;
    cin >> N;
    vector<ll> A(N);
    rep(i, N) cin >> A[i];

    vector<ll> cnt1(100);
    int maxbit = 0;
    rep(i, N) {
        ll tmp = A[i];
        int cnt = 0;
        while (tmp > 0) {
            if (tmp & 1) cnt1[cnt]++;
            cnt++;
            tmp >>= 1;
        }
        chmax(maxbit, cnt);
    }

    ll ans = 0;
    ll ct = 1;
    rep(i, maxbit) {
        ll t = cnt1[i] * (N - cnt1[i]);
        t %= MOD;
        ans += (t * ct) % MOD;
        ans %= MOD;
        ct *= 2;
        ct %= MOD;
    }

    cout << ans << endl;
    return 0;
}