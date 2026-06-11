#include <bits/stdc++.h>
using namespace std;

#define rep(i, beg, end) for (int i = (beg); i < (end); i++)
#define rrep(i, beg, end) for (int i = (beg); i >= (end); i--)
typedef long long ll;
typedef pair<ll, ll> P;
typedef unsigned long long ull;
const int INF = 2e9;
const int mod = 1e9 + 7;
const int N = 1010;
ll gcd(ll x, ll y) { return y ? gcd(y, x % y) : x; }

int main(void)
{
    int n,x; cin >> n >> x;
    int ans = 0;
    vector<int> l(n);
    rep(i,0,n) cin >> l[i];
    vector<int> D(n+1); D[0] = 0;
    rep(i,1,n+1) D[i] = D[i-1] + l[i-1];
    rep(i,0,n+1) {
        if(D[i] <= x)
            ans++;
    }
    cout << ans << endl;

    return 0;
}