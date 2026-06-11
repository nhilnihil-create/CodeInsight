#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int main()
{
    ll n, k;
    cin >> n >> k;
    vector<int> a(n);
    for(int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    map<ll, ll> m;
    vector<ll> sum(n+1, 0);
    for(int i = 0; i < n; i++)
    {
        sum[i+1] = sum[i] + a[i];
    }
    for(int i = 0; i <= min(n, k-1); i++)
    {
        ll cand = (sum[i]-i) % k;
        cand = (cand + k) % k;
        m[cand]++;
    }
    ll ans = 0;
    for(int i = 0; i < n; i++)
    {
        ll cand = (sum[i]-i) % k;
        cand = (cand + k) % k;
        m[cand]--;
        ans += m[cand];
        if(k+i <= n)
        {
            ll add = (sum[k+i]-(k+i)) % k;
            add = (add + k) % k;
            m[add]++;
        }
    }
    cout << ans << endl;
}

