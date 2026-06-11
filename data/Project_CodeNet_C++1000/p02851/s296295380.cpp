#pragma GCC optimize("O3")
#include <bits/stdc++.h>
#define ll long long
#define rep(i,n) for(ll i=0;i<(n);i++)
#define pll pair<ll,ll>
#define pii pair<int,int>
#define pq priority_queue
#define pb push_back
#define eb emplace_back
#define fi first
#define se second
#define endl '\n'
#define ios ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
#define lb(c,x) distance(c.begin(),lower_bound(all(c),x))
#define ub(c,x) distance(c.begin(),upper_bound(all(c),x))

using namespace std;

const ll INF=1e15;

int main() {
    ll n,k;
    cin >> n >> k;
    vector<ll> a(n),s(n+1);
    map<ll,ll> m;
    rep(i,n){
        cin >> a[i];
        s[i+1]=s[i]+a[i];
    }
    for(ll i=1;i<=n;i++){
        s[i]-=i;
        s[i]%=k;
    }
    ll ans=0;
    for(ll i=0;i<=n;i++){
        ans+=m[s[i]];
        if(i>=k-1) m[s[i-k+1]]--;
        m[s[i]]++;
    }
    cout << ans << endl;
    return 0;
}