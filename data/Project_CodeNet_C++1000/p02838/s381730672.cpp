#pragma GCC optimize("O3")
#include <bits/stdc++.h>
#define ll long long
#define rep(i,n) for(ll i=0;i<(n);i++)
#define pll pair<ll,ll>
#define pq priority_queue
#define pb push_back
#define eb emplace_back
#define fi first
#define se second
#define ios ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
#define lb(c,x) distance(c.begin(),lower_bound(all(c),x))
#define ub(c,x) distance(c.begin(),upper_bound(all(c),x))

using namespace std;

template<class T> inline bool chmax(T& a,T b){if(a<b){a=b;return 1;}return 0;}
template<class T> inline bool chmin(T& a,T b){if(a>b){a=b;return 1;}return 0;}

const ll mod=1e9+7;

int main()
{
    ll n;
    cin >> n;
    vector<ll> a(n);
    vector<ll> p(60);
    rep(i,60){
        if(i==0){
            p[i]=1;
            continue;
        }
        p[i]=p[i-1]*2;
        p[i]%=mod;
    }
    rep(i,n){
        cin >> a[i];
    }
    ll ans=0;
    rep(i,60){
        ll cnt1=0; //0の数
        ll cnt2=0; //1の数
        rep(j,n){
            if((a[j]>>i)%2==0){
                cnt1++;
            }
            else{
                cnt2++;
            }
        }
        ans+=(((cnt1*cnt2)%mod)*p[i])%mod;
        ans%=mod;
    }
    cout << ans << endl;
    return 0;
} 