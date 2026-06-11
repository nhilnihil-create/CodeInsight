#include <bits/stdc++.h> 
using namespace std;
using ll = long long;
template<typename T> using v2 = vector<vector<T>>;
template<typename T> inline v2<T> fill(int r, int c, const T& t){ return v2<T>(r, vector<T>(c, t)); }
#define F first
#define S second

void solve(){
    int n;
    cin >> n;
    int nc2 = n*(n-1)/2;
    v2<int> id = fill(n, n, -1);
    int num = 0;
    for(int i = 0; i < n; ++i){
        for(int j = i+1; j < n; ++j){
            id[i][j] = num;
            id[j][i] = num;
            ++num;
        }
    }
    
    v2<int> a = fill(n, n, -1);
    for(int i = 0; i < n; ++i){
        for(int j = 0; j < n-1; ++j){
            cin >> a[i][j];
            --a[i][j];
        }
    }

    v2<int> adj(nc2);
    vector<int> indeg(nc2);
    for(int i = 0; i < n; ++i){
        for(int j = 1; j < n-1; ++j){
            int gf = id[i][a[i][j-1]], gs = id[i][a[i][j]];
            adj[gf].push_back(gs);
            ++indeg[gs];
        }
    }

    queue<int> q;
    vector<int> day(nc2,0);
    for(int i = 0; i < n; ++i){
        for(int j = i+1; j < n; ++j){
            int g = id[i][j];
            if(indeg[g]==0){
                q.push(g);
                day[g]=1;
            }
        }
    }

    while(!q.empty()){
        int cur = q.front();
        q.pop();
        for(int next : adj[cur]){
            --indeg[next];
            if(indeg[next]==0){
                q.push(next);
                day[next] = 1+day[cur];
            }
        }
    }

    int ans = 0;
    for(int i = 0; i < nc2; ++i){
        if(day[i]==0){
            cout << "-1\n";
            return;
        }
        ans = max(ans, day[i]);
    }
    cout << ans << '\n';
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
    return 0;
}