#include <bits/stdc++.h>
#include<math.h>
#include<algorithm> 
#define rep(i,n) for (int i = 0; i < (n) ; ++i)
using namespace std;
using ll = long long ;
using P = pair<int, int> ;
#define PI 3.14159265358979323846264338327950
#define INF 1e18

int main() {
    int n, x, y ;
    cin >> n >> x >> y ;
    x-- ;
    y-- ;
    vector<vector<int>> g (n) ;
    rep(i, n-1){
        g[i].push_back(i + 1) ;
        g[i + 1].push_back(i) ;
    }
    g[x].push_back(y) ;
    g[y].push_back(x) ; 
    vector<vector<ll>> len (n, vector<ll> (n, INF)) ;
    rep(i, n){
        queue <P> que ;
        que.push(P(i, 0)) ;
        vector<bool> used (n, false) ;
        while(1){
            if(que.empty()){
                break ; 
            }
            P k = que.front() ;
            que.pop() ;
            ll num = k.first ;
            ll cost = k.second ; 
            used[num] = true ;
            len[i][num] = min(len[i][num], cost) ;
            len[num][i] = min(len[num][i], cost) ;
            int t = g[num].size() ;
            rep(j, t){
                if(!used[g[num][j]]){
                    que.push(P(g[num][j], cost + 1)) ;
                }
            }
        }
    }
    vector<int> ans (n) ;
    rep(i, n){
        rep(j, n){
            ans[len[i][j]]++ ;
        }
    }
    rep(i, n){
        ans[i] /= 2 ;
    }
    for(int i = 1; i < n ; i++){
        cout << ans[i] << endl ;
    }
    return 0 ;
}  