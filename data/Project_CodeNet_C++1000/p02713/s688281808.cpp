#include <bits/stdc++.h>
#define rep(i,n) for(int i=0; i<(n); i++)
#define rep2(i,x,n) for(int i=x; i<(n); i++)
#define ALL(c) (c).begin(), (c).end()
#define pb push_back
#define eb emplace_back
using namespace std;
const long long INF = 1LL<<60; // 仮想的な無限大の値;
using ll = long long;
using P  = pair<int, int>;
#define vi vector<int>
#define vll vector<ll>
#define vs vector<string>
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
long long GCD(long long a, long long b) {
    if (b == 0) return a;
    else return GCD(b, a % b);
}
int main()
{
    ll x;cin >>x;++x;
    ll ans = 0;
    rep2(i,1, x)rep2(j,1, x)rep2(k, 1,x)
    {
        ll z = GCD(GCD(i, j), k);
        ans += z;
    }
    cout << ans << endl;

    return 0;
}