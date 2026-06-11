#include <bits/stdc++.h>
#define rep(i,n) for(int i=0; i<(n); i++)
#define reps(i,s,n) for(int i=(s); i<(n); i++)
#define all(v) v.begin(),v.end()
#define outve(v) for(auto i : v) cout << i << " ";cout << endl
#define outmat(v) for(auto i : v){for(auto j : i) cout << j << " ";cout << endl;}
#define in(n,v) for(int i=0; i<(n); i++){cin >> v[i];}
#define out(n) cout << (n) << endl
#define fi first
#define se second
#define pb push_back
#define mod 1000000007
#define infi 1900000000
#define infl 1100000000000000000
#define cyes cout << "Yes" << endl
#define cno cout << "No" << endl
#define csp << " " <<
#define outset(n) cout << fixed << setprecision(n);
using namespace std;
using ll = long long;
using ld = long double;
using vi = vector<int>;
using vvi = vector<vector<int>>;
using vl = vector<ll>;
using vvl = vector<vector<ll>>;
using pii = pair<int,int>;
using pll = pair<ll,ll>;
template<typename T> using ve = vector<T>;
template<typename T> using pq2 = priority_queue<T>;
template<typename T> using pq1 = priority_queue<T,vector<T>,greater<T>>;




int main()
{
    int N;
    ll K;
    cin >> N >> K;
    ve<ve<int>> G(N);
    rep(i,N-1){
        int a,b;
        cin >> a >> b;
        a--,b--;
        G[a].pb(b);
        G[b].pb(a);
    }
    
    
    
    queue<pii> Q;
    Q.push({0,-1});
    ll ans = 0;
    ans = K;
    
    while (!Q.empty()) {
        pii u = Q.front();
        Q.pop();
        
        for (int v : G[u.fi]) {
            if(v == u.se) continue;
            Q.push({v,u.fi});
        }
        ll aa = G[u.fi].size();
        if(u.fi != 0) aa--;
        if(u.fi == 0){
            for (ll bb = K-1; bb > K-1-aa; bb--) {
                ans *= bb;
                ans %= mod;
            }
        }else{
            for (ll bb = K-2; bb > K-2-aa; bb--) {
                ans *= bb;
                ans %= mod;
                
            }
        }
        
        
    }
    cout << ans << endl;

    
    
    
    

    return 0;
}
