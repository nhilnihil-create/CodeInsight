#include <bits/stdc++.h>
#define ll long long

using namespace std;

int main()
{
    ll n;
    cin >> n;
    vector<pair<ll, ll> > v(n+1);
    for(ll i=1; i<=n; i++){
        cin >> v[i].first;
        v[i].second=i;
    }
    sort(v.begin()+1, v.end(), greater<pair<ll, ll> >());
    ll dp[n+1][n+1];
    memset(dp, (ll)0, sizeof(dp));
    for(ll i=1; i<=n; i++){
        for(ll j=0; j<=i-1; j++){
            ll L=j, R=i-1-j;
            dp[L+1][R]=max(dp[L+1][R], dp[L][R]+(ll)abs(L+1-v[i].second)*v[i].first);
            R=j, L=i-1-j;
            dp[L][R+1]=max(dp[L][R+1], dp[L][R]+(ll)abs(n-R-v[i].second)*v[i].first);
        }
    }
    ll ans=-1;
    for(ll j=0; j<=n; j++)
        ans=max(ans, dp[j][n-j]);
    cout << ans << endl;
	return 0;
}
