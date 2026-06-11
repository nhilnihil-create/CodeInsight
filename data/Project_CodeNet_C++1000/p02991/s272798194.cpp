#include<bits/stdc++.h> 
#define IOS ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define pb push_back
#define int long long
#define swap(x,y) (x^=y^=x^=y)

#define debug1(a) cerr<<#a<<" = "<<(a)<<endl;
#define debug2(a,b) cerr<<#a<<" = "<<(a)<<", "<<#b<<" = "<<(b)<<endl;
#define debug3(a,b,c) cerr<<#a<<" = "<<(a)<<", "<<#b<<" = "<<(b)<<", "<<#c<<" = "<<(c)<<endl;
#define debug4(a,b,c,d) cerr<<#a<<" = "<<(a)<<", "<<#b<<" = "<<(b)<<", "<<#c<<" = "<<(c)<<", "<<#d<<" = "<<(d)<<endl;

using namespace std;

#define mod 1000000007
long long modexpo(long long x, long long p){
    int res = 1;x = x%mod;
    while(p){
        if(p%2)res = res * x;
        p >>= 1;
        x = x*x % mod;
        res %= mod;
    }
    return res;
}

// int max(int a,int b){return (a>b?a:b);} 
// int min(int a,int b){return (a<b?a:b);}


struct compare{
    bool operator() (const pair<int,int> a, const pair<int,int> b) const{
        return a.first < b.first;
    }
};

const int nax = 1e5 + 5;
vector<pair<int,int>> g[nax][3];
int n,m,s,t;
int dist[nax][3];
int32_t main(){
    IOS
    cin >> n >> m;
    for(int i = 0; i < m; i++){
        int a,b;
        cin >> a >> b;
        g[a][0].pb({b,1});
        g[a][1].pb({b,2});
        g[a][2].pb({b,0});
    }
    cin >> s >> t;
    for(int i = 1; i <= n; i++){
        dist[i][0] = dist[i][1] = dist[i][2] = 1e12;
    }
    set<pair<int, pair<int,int>>> q;
    q.insert({0,{s,0}});
    dist[s][0] = 0;
    int ans = 1e18;
    while(!q.empty()){
        int x = q.begin()->second.first;
        int y = q.begin()->second.second;
        q.erase(q.begin());
        for(auto it : g[x][y]){
            if(dist[it.first][it.second] > dist[x][y] + 1){
                q.erase({dist[it.first][it.second], {it.first, it.second}});
                dist[it.first][it.second] = dist[x][y] + 1;
                q.insert({dist[it.first][it.second], {it.first, it.second}});
                if((dist[it.first][it.second])%3 == 0 && it.first == t){
                    // debug3(it.first, it.second, dist[it.first][it.second]);
                    ans = min(ans, dist[it.first][it.second]);
                }
            }
        }
    }
    if(ans == 1e18){
        cout << -1 << endl;
    }
    else{
        cout << ans/3 << endl;
    }
} 