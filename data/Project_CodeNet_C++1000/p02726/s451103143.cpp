#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;

#define INF 1e9
#define st string
#define pb push_back
#define eb emplace_back
#define pii pair<int, int>
#define fopen freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout);
#define fastio ios_base::sync_with_stdio(false); cin.tie(NULL);
#define test(x) int t; cin >> t; while(t--) x();

int dx[] = {0, 0, 1, -1};
int dy[] = {1, -1, 0, 0};

vector<int>adj[20005];
map<int, int>ans;
bool vist[20005];
int dist[20005];
int n;

void bfs(int start){
    queue<int>q;;
    q.push(start);
    vist[start] = true;
    dist[start] = 0;
    while(!q.empty()){
        int x = q.front(); q.pop();
        for(auto neigh : adj[x]){
            if(!vist[neigh]){
                vist[neigh] = true;
                dist[neigh] = dist[x] + 1;
                q.push(neigh);
            }
        }
    }
    for(int i = 0; i < n; i++){
        ans[dist[i]]++;
    }
    for(int i = 0; i < n; i++) {
        dist[i] = 0;
        vist[i] = false;
    }
}

void solve(){
    int x, y; cin >> n >> x >> y;
    for(int i = 1; i < n; i++){
        adj[i - 1].pb(i);
        adj[i].pb(i - 1);
    }
    adj[x-1].pb(y-1);
    adj[y-1].pb(x-1);

    for(int i = 0; i < n; i++) {
        bfs(i);
    }
    for(int i = 1; i < n; i++){
        cout << ans[i] / 2 << endl;
    }
}

int main(){
    fastio
    solve();
    return 0;
}

