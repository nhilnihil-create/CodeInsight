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

const ll mod=1e9+7;


int main(){
    ll n,k;
    cin >> n >> k;
    vector<ll> a(n);
    ll sum=0;
    rep(i,n){
        cin >> a[i];
        sum+=a[i];
    }
    vector<ll> p;
    for(ll i=1;i*i<=sum;i++){
        if(sum%i==0){
            if(i*i==sum){
                p.push_back(i);
            }
            else{
                p.push_back(i);
                p.push_back(sum/i);
            }
        }
    }
    ll ans=0;
    for(ll x:p){
        ll tot=0;
        ll cnt=0;
        vector<ll> r;
        rep(i,n){
            ll s=a[i]%x;
            ll t=x-(a[i]%x);
            tot+=min(s,t);
            if(s<t){
                cnt+=(a[i]/x)*x;
                r.push_back(s);
            }
            else{
                cnt+=(a[i]/x+1)*x;
                r.push_back(-t);
            }
        }
        sort(r.begin(),r.end());
        if(cnt>sum){
            ll times=(cnt-sum)/x;
            rep(j,times){
                tot-=abs(r[j]);
                tot+=x-abs(r[j]);
            }
        }
        if(cnt<sum){
            ll times=(sum-cnt)/x;
            rep(j,times){
                tot-=abs(r[n-1-j]);
                tot+=x-abs(r[n-1-j]);
            }
        }
        if(tot<=2*k) ans=max(ans,x);
    }
    cout << ans << endl;
    return 0;
}