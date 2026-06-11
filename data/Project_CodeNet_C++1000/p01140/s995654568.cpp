#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define FOR(i,a,b) for(int i=(a);i<(int)(b);i++)
#define rep(i,n) FOR(i,0,n)
#define ALL(x) (x).begin(),(x).end()
#define ZERO(a) memset(a,0,sizeof(a))

const int M = 1500;
ll h[M+5], w[M+5];

void solve(int H, int W) {
    ZERO(h); ZERO(w);
    FOR(i,1,H+1) scanf("%lld", &h[i]);
    FOR(i,1,W+1) scanf("%lld", &w[i]);

    rep(i,H) h[i+1] += h[i];
    rep(i,W) w[i+1] += w[i];

    map<ll,ll> nums;
    FOR(i,1,W+1) rep(j,i) nums[w[i]-w[j]]++;

    ll ans = 0;
    FOR(i,1,H+1) {
        rep(j,i) {
            ll height = h[i] - h[j];
            ans += nums[height];
        }
    }

    cout << ans << endl;
}

int main() {
    int H, W;
    while(cin>>H>>W, H) solve(H,W);
    return 0;
}