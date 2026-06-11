#include <bits/stdc++.h>
using namespace std;

typedef long long       ll;
const int MOD=1000000007;
const int MAX=1e5+9;
ll cnt[MAX];

ll fastPow(ll a, ll b) {
    if (!b) {
        return 1;
    }

    ll sq=fastPow(a, (b>>1LL));
    sq*=sq;

    if (b&1LL) {
        sq%=MOD;
        sq*=a;
    }

    return sq%MOD;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, k;
    cin >> n >> k;
    ll ans=0;
    for (int i=k; i>=1; --i) {
        int mul=k/i;
        if (!mul) {
            continue;
        }

        cnt[i]=fastPow(mul, n);
        for (int j=2; 1LL*j*i<=k; ++j) {
            cnt[i]-=cnt[j*i];
            if (cnt[i]<MOD) {
                cnt[i]+=MOD;
            }
        }

        ans+=(1LL*i*cnt[i])%MOD;
        ans%=MOD;
    }

    cout << ans;

    return 0;
}
