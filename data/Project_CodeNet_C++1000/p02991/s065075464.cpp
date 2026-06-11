#include <bits/stdc++.h>
using namespace std;

#define MOD 10000007
#define f first
#define s second
#define es " "
#define pb push_back
#define endl "\n"
#define INF 0x3f3f3f3f
#define INFL 0x3f3f3f3f3f3f3f3f
#define ll long long int
#define fastio ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0)

int n, e, s, m, memo[100005][5];

vector<int> viz[100005];

int bfs(){
    queue<pair<int, int> > fila;
    fila.push({e, 0});
    while(!fila.empty()){
        int pos=fila.front().f;
        int dist=fila.front().s;
        fila.pop();
        if(pos==s && dist%3==0){
            return dist/3;
        }
        if(memo[pos][dist%3]) continue;
        memo[pos][dist%3]=1;
        for(int i=0; i<viz[pos].size(); i++){
            int u=viz[pos][i];
            fila.push({u, dist+1});
        }
    }
    return -1;
}

int main(){
    cin >> n >> m;
    for(int i=0, a, b; i<m; i++){
        cin >> a >> b;
        viz[a].pb(b);
    }
    cin >> e >> s;
    cout << bfs() << endl;
    return 0;
}