#include<iostream>
#include<iomanip>
#include<vector>
#include<string>
#include<cstring>
#include<map>
#include<set>
#include<queue>
#include<stack>
#include<algorithm>
#include<cmath>
#include<cstdio>
#include<cstdlib>
#include<climits>
#include<fstream>

#define MOD (1000000007)

using namespace std;

typedef long long int Int;

constexpr Int TEN(int n) { return n == 0 ? 1 : 10 * TEN(n-1); }

const int max_n = 100000+19;
int N,M;
int S,T;
vector<pair<int,int>> G[max_n][3];
bool visited[max_n][3];
int dist[max_n][3];

int main(void) {
    cin>>N>>M;

    int inf = TEN(8);

    for(int i = 1;i <= N;i++) {
        for(int j = 0;j < 3;j++) {
            dist[i][j] = inf;
        }
    }

    for(int i = 0;i < M;i++) {
        int u,v;
        cin>>u>>v;
        G[u][0].push_back({v,1});
        G[u][1].push_back({v,2});
        G[u][2].push_back({v,0});
    }
    cin>>S>>T;

    priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,greater<pair<int,pair<int,int>>>> Q; //dist, node, state
    Q.push({0, make_pair(S, 0)});
    
    while(!Q.empty()) {
        pair<int,pair<int,int>> p = Q.top();Q.pop();
        if(visited[p.second.first][p.second.second])
            continue;
        visited[p.second.first][p.second.second] = true;

        for(auto u: G[p.second.first][p.second.second]) {
            int node = u.first;
            int state = u.second;
            if(p.first+1 < dist[node][state]) {
                dist[node][state] = p.first+1;
            }
            Q.push({p.first+1,make_pair(node, state)});
        }
    }

    if(dist[T][0] == inf)
        cout<<-1<<endl;
    else
        cout<<dist[T][0]/3<<endl;


    return 0;
}
