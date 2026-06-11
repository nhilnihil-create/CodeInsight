#include <iostream>
#include <vector>

using namespace std;
const int N = 1e5 + 1;
int n,m;
int a[N];
vector <int> adj[N];
int main(){
    cin >> n >> m;
    for (int i = 1; i <= n; i++) cin >> a[i];
    for (int i = 1; i <= m; i++){
        int u , v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    int ans = 0;
    for (int i = 1; i <= n; i++){
        bool check = true;
        for (auto j : adj[i])
            if (a[j] >= a[i]) check = false;
        if (check == true) ans++;
    }
    cout << ans;
    return 0;
}