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

const int max_n = 100000+10;
int N,M;
int S,T;
vector<pair<int,int> > G[max_n][3]; //node, state
int visited[max_n][3];

int solve(void) {
    for(int i = 0;i < max_n;i++) {
        for(int j = 0;j < 3;j++) {
            visited[i][j] = -1;
        }
    }

    queue<pair<int, pair<int,int> > > Q;
    Q.push({S,{0, 0}}); //node, next_node, distance
    while(!Q.empty()) {
        auto u = Q.front();Q.pop();
        if(visited[u.first][u.second.first] != -1)
            continue;
        visited[u.first][u.second.first] = u.second.second;

        for(auto v: G[u.first][u.second.first]) {
            Q.push({v.first,{v.second, u.second.second+1}});
        }
    }

    return visited[T][0] == -1 ? -1 : visited[T][0]/3;
}

int main(void) {
    cin>>N>>M;

    for(int i = 0;i < M;i++) {
        int u,v;
        cin>>u>>v;
        G[u][0].push_back({v, 1});
        G[u][1].push_back({v, 2});
        G[u][2].push_back({v, 0});
    }

    cin>>S>>T;
    cout<<solve()<<endl;

    return 0;
}
