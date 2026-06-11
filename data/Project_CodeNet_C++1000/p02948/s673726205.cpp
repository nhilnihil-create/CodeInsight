#include <bits/stdc++.h>
#include<math.h>
#include<algorithm> 
#define rep(i,n) for (int i = 0; i < (n) ; ++i)
using namespace std;
using ll = long long ;
using P = pair<int, int> ;
using PL = pair<ll , ll> ;
#define PI 3.14159265358979323846264338327950
#define INF 1e18
#define mod 1000000007

int main(){
    int n, m ;
    vector<vector<int>> vec (1000005) ;
    cin >> n >> m ;
    rep(i, n){
        int a, b ;
        cin >> a >> b ;
        a-- ;
        vec[a].push_back(b) ;
    }
    int ans = 0 ;
    priority_queue<int, vector<int>> que ;
    rep(i, m){
        int k = vec[i].size() ;
        rep(j, k){
            que.push(vec[i][j]) ;
        }
        if(!que.empty()){
            ans += que.top() ;
            que.pop() ;
        }
    }
    cout << ans << endl ;
}