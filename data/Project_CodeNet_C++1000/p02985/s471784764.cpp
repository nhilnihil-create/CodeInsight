#include <iostream>
#include <utility>
#include <queue>
#include <memory>
#include <cstring>
#include <vector>
#include <algorithm>
#include <functional>

#define reps(i,s,n) for(int i = s; i < n; i++)
#define rep(i,n) reps(i,0,n)

using namespace std;
using ll = long long;
const int mod = 1e9+7;

vector<int> col(100010);
vector<int> graph[100010];
vector<bool> visit(100010,false);

int n,k;
ll ans = 1;

void dfs(int x,int p){
    visit[x] = true;
    
    int cnt = 0;

    if(p != -1){
        col[p]++;
        col[x]++;
        ans = (ans * (k-col[p])) % mod;
    }else{
        ans = k;
    }
    for(auto e: graph[x]){
        if(visit[e]){
            continue;
        }
        dfs(e,x);   
    }
}

int main(){
    cin >> n >> k;
    rep(i,n-1){
        int a,b;
        cin >> a >> b;
        a--; b--;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }

    dfs(0,-1);
    cout << ans << endl;
    return 0;
}
