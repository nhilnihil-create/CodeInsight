#include <bits/stdc++.h>
using namespace std;
#define repd(i,a,b) for (int i=(a);i<(b);i++)
#define rep(i,n) repd(i,0,n)
#define all(x) (x).begin(),(x).end()
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }
typedef long long ll;
const long long INF = 1LL << 60;
typedef pair<int, int> P;

ll gcd(ll a, ll b) {
    if (b == 0) return a;
    return gcd(b, a % b);
}

ll lcm(ll a, ll b) {
    return a * b / gcd(a, b);
}

int main()
{
    ll N, M;
    cin >> N >> M;
    vector<ll> A(N);
    rep(i, N) cin >> A[i];

    ll L = 1;
    rep(i, N) L = lcm(L, A[i]);

    M *= 2;
    bool flag = true;
    rep(i, N) {
        if ((L / A[i]) % 2 == 0) flag = false; 
    }

    ll ans = 0;
    if (flag) {
        ans = M / L;
        ans = (ans + 1) / 2;
    }

    cout << ans << endl;
    return 0;
}