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
    ll n,k;
    cin >> n >> k;
    ll m=(n-2)*(n-1)/2;
    if(k>m){
        cout << -1 << endl;
        return 0;
    }
    ll diff=m-k;
    vector<vector<ll>> g(n,vector<ll>(n)),used(n,vector<ll>(n));
    rep(i,n){
        if(i==0) continue;
        g[i][0]=g[0][i]=1;
    }
    rep(i,n){
        bool fin=false;
        rep(j,n){
            if(diff==0){
                fin=true;
                break;
            }
            
            if(i==j) continue;
            if(i==0 || j==0) continue;
            if(g[i][j]!=1 && g[j][i]!=1){
                g[i][j]=g[j][i]=1;
                diff--;
            }
        }
        if(fin) break;
    }
    vector<pll> ans;
    rep(i,n){
        rep(j,n){
            if(g[i][j]==1 && g[j][i]==1 && used[j][i]==0 && used[i][j]==0){
                ans.push_back(make_pair(i+1,j+1));
                used[i][j]=used[j][i]=1;
            }
        }
    }
    ll v=ans.size();
    cout << v << endl;
    rep(i,v){
        cout << ans[i].fi << " " << ans[i].se << endl;
    }
    return 0;
} 