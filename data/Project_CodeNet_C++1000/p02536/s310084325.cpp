
  #include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <utility>

#define faster ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define pb push_back
#define mp make_pair

typedef long long  ll;
using namespace std;
int inf = 1e9;
const int N = 100005;
int n, m;
vector<int> g[N];
bool was[N];

void dfs(int v){
    was[v] = true;
    for(int to : g[v]){
        if(!was[to]){
            dfs(to);
        }
    }
}

int main(){
    faster
    cin >> n >> m;
    int cnt = 0;
    for(int i = 0;i < m;i++){
        int x, y; cin >> x >> y;
        g[x].push_back(y);
        g[y].push_back(x);
    }
    for(int i = 1;i <= n;i++){
        if(!was[i]){
            dfs(i);
            cnt++;
        }
    }
    cout << cnt - 1 << endl;
    return 0;
}
