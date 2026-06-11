#include<bits/stdc++.h>
#define rep(i,n,m) for(int i = (n); i <(m); i++)
#define rrep(i,n,m) for(int i = (n) - 1; i >=(m); i--)
#define pvec(vec) {for (auto v: vec) cout << v << ' '; cout << endl;}
#define pivec(vec) {rep(i, 0, vec.size()) cout << i << ':' << vec[i] << ' '; cout << endl;}

using namespace std;
using ll = long long;

ll solve(ll X, ll K, ll D)
{
    X = abs(X);
    ll left_cnt = X / D;

    if (left_cnt >= K)
        return X - K * D;
    else
        return min(abs(X-left_cnt*D), abs(X-(left_cnt+1)*D));
}

int main()
{
    ll X, K, D;
    cin >> X >> K >> D;

    ll ans = 1e15;
    if (K&1)
        ans = min(solve(X+D, K/2, D*2), solve(X-D, K/2, D*2));
    else
        ans = solve(X, K/2, D*2);

    cout << ans << endl;
    return 0;
}
