#include<bits/stdc++.h>
#define ll long long
#define pr pair<ll,ll>
using namespace std;
ll cnt[300005];
bool vis[300005];
int main() {
    int n;
    cin >> n;
    vector<ll> nn;
    for (int i = 0; i < n; i++) {
        ll a;
        cin >> a;
        cnt[a]++;
        if (!vis[a]) {
            vis[a] = 1;
            nn.push_back(a);
        }
    }
    for (int i = 0; i < nn.size(); i++) {
        nn[i] = cnt[nn[i]];
    }
    sort(nn.begin(), nn.end());
    vector<ll> pre;
    pre.push_back(nn[0]);
    for (int i = 1; i < nn.size(); i++) {
        pre.push_back(pre.back() + nn[i]);
    }
    cout << n << '\n';
    for (ll i = 2; i <= n; i++) {
        ll l = 0, r = 1LL*n / i;
        while (l != r) {
            ll m = l + r + 1 >> 1;
            ll p = lower_bound(nn.begin(),nn.end(), m) - nn.begin();
            ll sum=0;
            if (p)sum = pre[p - 1];
            ll x = nn.size() - p;
            if (x + sum / m >= i) {
                if (l == m)break;
                l = m;
            }
            else if (r == m)break;
            else r = m;
        }
        cout << l << '\n';
    }
    return 0;
}