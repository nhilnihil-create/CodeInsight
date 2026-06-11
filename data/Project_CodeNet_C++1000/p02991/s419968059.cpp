#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int N = 2e5+5;

int n;
int m;
int s , t;
vector < int > adj[N];

bool vis[N][3];

struct state{
    int u;
    int dist;
};

int main(){
    scanf("%d%d " , &n , &m);
    for(int i = 1; i <= m; i++){
        int u , v;
        scanf(" %d%d" , &u , &v);
        adj[u].push_back(v);
    }
    scanf(" %d%d" , &s , &t);
    queue < state > q;
    q.push({s , 0});
    while(!q.empty()){
        int u = q.front().u;
        int dist = q.front().dist;
        q.pop();
        if(u == t && dist % 3 == 0){
            printf("%d\n" , dist / 3);
            return 0;
        }
        vis[u][dist % 3] = 1;
        for(auto v : adj[u]){
            if(!vis[v][ (dist + 1)%3 ]){
                vis[v][ (dist + 1)%3 ] = 1;
                q.push({v , dist + 1});
            }
        }
    }
    puts("-1");
}
