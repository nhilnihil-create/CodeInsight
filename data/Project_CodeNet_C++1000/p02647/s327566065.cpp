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

const ll INF=1e18;
const ll mod=1e9+7;

int main(){
    ll n,k;
    cin >> n >> k;
    vector<ll> cur(n+1),next(n+1);
    rep(i,n){
        cin >> cur[i];
    }
    rep(i,k){
        bool all=true;
        rep(j,n){
            ll pos1=max(j-cur[j],0LL);
            ll pos2=min(j+cur[j]+1,n);
            next[pos1]++;
            next[pos2]--;
        }
        rep(j,n+1){
            if(j){
                next[j]+=next[j-1];
            }
        }
        rep(j,n){
            if(cur[j]!=next[j]) all=false;
        }
        cur=next;
        next=vector<ll>(n);
        if(all) break;
    }
    rep(i,n){
        if(i) cout << " ";
        cout << cur[i];
    }
    cout << endl;
    return 0;
}
