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



int main(){
    ll n,p;
    cin >> n >> p;
    string s;
    cin >> s;
    if(p==2 || p==5){
        ll ans=0;
        rep(i,n){
            ll num=s[n-1-i]-'0';
            if(num%p==0){
                ans+=n-i;
            }
        }
        cout << ans << endl;
        return 0;
    }
    vector<ll> sum(n+1),cnt(p);
    vector<ll> q(n);
    ll val=1;
    rep(i,n){
        q[i]=val;
        val*=10;
        val%=p;
    }
    rep(i,n){
        ll num=s[n-1-i]-'0';
        sum[i+1]=sum[i]+num*q[i];
        sum[i+1]%=p;
    }
    rep(i,n+1){
        cnt[sum[i]]++;
    }
    ll ans=0;
    rep(i,p){
        if(cnt[i]>=2){
            ans+=cnt[i]*(cnt[i]-1)/2;
        }
    }
    cout << ans << endl;
    return 0;
}