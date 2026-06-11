#include <bits/stdc++.h>
using namespace std;
#define repd(i,a,b) for (ll i=(a);i<(b);i++)
#define rep(i,n) repd(i,0,n)
#define all(x) (x).begin(),(x).end()
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }
typedef long long ll;
const long long INF = 1LL << 60;
typedef pair<int, int> P;
int main()
{
    ll N;
    cin >> N;
/*
    repd(i, 2, N + 1) {
        ll t = N;
        while (t % i == 0) {
            t /= i;
        }
        if (t % i == 1) cout << i << endl;
    }
    */

    ll ans = 0;
    set<ll> st;
    for (ll i = 2; i * i <= N; i++) {
        ll t = N;
        while (t % i == 0) {
            t /= i;
        }
        if (t % i == 1) {
            if (st.count(i) == 0) {
                ans++;
                st.insert(i);
            }
            ll n = N;
            ll t2 = N / i;
            while (n % t2 == 0) {
                n /= t2;
            }
            if (n % t2 == 1 && st.count(t2) == 0) {
                ans++;
                st.insert(t2);
            }
        }
    }

    if (st.count(N) == 0) ans++;
    if (st.count(N - 1) == 0 && N - 1 > 1) ans++;
    cout << ans << endl;
    return 0;
}