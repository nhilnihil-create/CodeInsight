#include<bits/stdc++.h>
 
#define rep(i,n) for(ll i = 0;i < n;++i)
#define all(v) v.begin(),v.end()
using namespace std;
using ll = long long;
typedef pair<int,int> P;
 
const int INF = 1001001001;
const long double PI = (acos(-1));
const int mod = 1e9+7;
const int vx[6] = {0,1,0,-1,1,-1};
const int vy[6] = {1,0,-1,0,1,1};




int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n,cc;
    cin >> n >> cc;
    vector<vector<int>> graph(n);
    rep(i,n-1){
        int x,y;
        cin >> x >> y;
        x--;y--;
        graph[x].push_back(y);
        graph[y].push_back(x);
    }
    vector<int> c(n,0);
    rep(i,cc){
        int p,x;
        cin >> p >> x;
        p--;
        c[p] += x;
    }
    queue<int> q;
    q.push(0);
    vector<int> memo(n,-1);
    while(!q.empty()){
        int x = q.front();q.pop();
        memo[x] = 1;
        for(auto t : graph[x]){
            if(t == 0) continue;
            if(memo[t] != -1) continue;
            c[t] += c[x];
            q.push(t);
        }
    }
    rep(i,n){
        cout << c[i] << " ";
    }
    cout << endl;
    return 0;
}
