#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0; i<n; i++)
typedef long long ll;
typedef pair<int,int> Pair;
const int INF = 1e9;
const int MOD = 1e9+7;
const ll INFL = 1e18;


int main(){
    int n,q;
    cin >> n >> q;
    vector<vector<int>> to(n);
    vector<int> scores(n);
    for(int i=0; i<n-1; i++){
        int a,b; cin >> a >> b;
        --a; --b;
        to[a].push_back(b);
        to[b].push_back(a);
    }
    for(int i=0; i<q; i++){
        int p,x; cin >> p >> x;
        --p;
        scores[p] += x;
    }
    vector<bool> isused(n,false);
    isused[0] = true;
    queue<int> que;
    que.emplace(0);
    isused[0] = true;
    while(!que.empty()){
        int node = que.front();
        que.pop();
        for(int i=0; i<int(to[node].size()); i++){
            int next = to[node][i];
            if(isused[next]) continue;
            isused[next] = true;
            scores[next] += scores[node];
            que.emplace(next);
        }
    }
    for(int i=0; i<n; i++){
        printf("%d%c",scores[i],i==n-1?'\n':' ');
    }
    return 0;
}  