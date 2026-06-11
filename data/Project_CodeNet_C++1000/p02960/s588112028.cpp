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

ll dp[100005][15];

int main()
{
    string s;
    cin >> s;
    ll n=s.length();
    vector<ll> p(n);
    ll v=1;
    rep(i,n){
        p[i]=v;
        v*=10;
        v%=13;
    }
    dp[0][0]=1;
    for(ll i=0;i<n;i++){
        rep(j,13){
            if(s[n-1-i]=='?'){
                rep(k,10){
                    dp[i+1][(j+k*p[i]%13)%13]+=dp[i][j];
                    dp[i+1][(j+k*p[i]%13)%13]%=mod;
                }
            }
            else{
                ll num=(ll)(s[n-1-i]-'0');
                dp[i+1][(j+num*p[i]%13)%13]+=dp[i][j];
                dp[i+1][(j+num*p[i]%13)%13]%=mod;
            }
            
        }
    }
    cout  << dp[n][5] << endl;
    return 0;
} 