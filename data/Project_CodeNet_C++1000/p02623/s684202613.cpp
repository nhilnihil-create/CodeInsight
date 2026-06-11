#include <bits/stdc++.h>
#define rep(i,n) for(int i=0; i<(n); i++)
#define rep2(i,x,n) for(int i=x; i<(n); i++)
#define ALL(c) (c).begin(), (c).end()
#define pb push_back
#define eb emplace_back
const long long INF = 1LL<<60; // 仮想的な無限大の値;
using namespace std;
using ll = long long;
using P  = pair<int, int>;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }

int main()
{
    ll N, M, K;
    cin >> N >> M >> K;
    vector<ll> A, B;
    rep(i, N)
    {
        ll x;
        cin >> x;
        A.pb(x);
    }
    rep(i, M)
    {
        ll x;
        cin >> x;
        B.pb(x);
    }
    vector<ll> SB(M);
    rep(i, M)
    {
        if(i==0) SB[i] = B[i];
        else
        {
            SB[i] = SB[i-1] + B[i];
        }      
    }
    ll ans = 0;
    ll s=0;
    auto pos = lower_bound(ALL(SB), K+1);
    ll x = pos - SB.begin();
    chmax(ans, x);
    rep(i, N)
    {
        s += A[i];
        ll k = K-s;
        if(k < 0) break;
        auto pos = lower_bound(ALL(SB), k+1);
        ll x = pos - SB.begin();
        chmax(ans, x+i+1);
    }
    cout << ans << endl;
    return 0;
}