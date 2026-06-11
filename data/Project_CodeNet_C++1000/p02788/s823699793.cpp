#include <bits/stdc++.h>
using namespace std;
#define repd(i,a,b) for (int i=(a);i<(b);i++)
#define rep(i,n) repd(i,0,n)
#define all(x) (x).begin(),(x).end()
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }
typedef long long ll;
const long long INF = 1LL << 60;
typedef pair<int, ll> P;
int main()
{
    int N, D, A;
    cin >> N >> D >> A;
    vector<P> M(N);
    vector<int> X(N);
    rep(i, N) {
        int x, h;
        cin >> x >> h;
        M[i] = {x, h};
        X[i] = x;
    }

    D *= 2;
    sort(all(M));
    sort(all(X));

    vector<ll> R(N + 1);
    ll ans = 0;
    rep(i, N) {
        if (i > 0) R[i] += R[i - 1];
        ll hp = M[i].second + R[i];
        if (hp <= 0) continue;
        ll cnt = (hp + A - 1) / A;
        //cout << i << " " << cnt << endl;
        ans += cnt;
        int index = upper_bound(all(X), X[i] + D) - X.begin();
        R[index] += cnt * A;
        R[i] -= cnt * A;
    }
/*
    rep(i, N + 1) {
        cout << R[i] << endl;
    }
    */
    cout << ans << endl;
    return 0;
}