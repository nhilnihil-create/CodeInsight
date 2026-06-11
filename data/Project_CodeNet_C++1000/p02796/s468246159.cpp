#include <bits/stdc++.h>

using namespace std;
typedef long long int ll;

int main()
{
    ll N;
    cin >> N;
    vector<pair<ll,ll>>v(N);
    for(int i = 0; i < N; i++)
    {
        ll x,l;
        cin >> x >> l;
        v[i] = pair(x + l, x - l);
    }
    sort(v.begin(),v.end());
    vector<bool>f(N,false);
    ll now = 0;
    f[now] = true;
    for(ll i = 0; i < N; i++)
    {
        if(v[now].first <= v[i].second) f[i] = true, now = i;
    }
    int ans = 0;
    for(ll i = 0; i < N; i++)
    {
        if(f[i]) ans++;
    }
    cout << ans << endl;
}