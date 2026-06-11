
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

inline int topbit(unsigned long long x){
	return x?63-__builtin_clzll(x):-1;
}

inline int popcount(unsigned long long x){
	return __builtin_popcountll(x);
}

inline int parity(unsigned long long x){//popcount%2
	return __builtin_parity(x);
}



template<class T> inline bool chmax(T& a,T b){if(a<b){a=b;return 1;}return 0;}
template<class T> inline bool chmin(T& a,T b){if(a>b){a=b;return 1;}return 0;}

const ll INF=1e9+7;

int main(){
    string s,t;
    cin >> s >> t;
    ll n=s.length();
    ll m=t.length();
    vector<vector<ll>> dp(2*n+1,vector<ll>(26,INF));
    vector<vector<ll>> pos(26);
    string u=s+s;
    rep(i,2*n){
        ll v=u[i]-'a';
        pos[v].push_back(i+1);
    }
    rep(i,2*n){
        rep(j,26){
            auto it=upper_bound(pos[j].begin(),pos[j].end(),i)-pos[j].begin();
            if(it==pos[j].size()){
                continue;
            }
            dp[i][j]=pos[j][it];
        }
    }
    ll p=0;
    ll ans=0;
    rep(i,m){
        ll num=t[i]-'a';
        ll nxt=dp[p][num];
        if(nxt==INF){
            cout << -1 << endl;
            return 0;
        }
        ans+=nxt-p;
        p=(nxt-1)%n+1;
    }
    cout << ans << endl;
    return 0;
}