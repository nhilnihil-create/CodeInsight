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

typedef pair<int,int> P;
const int max_n = 100000+19;
int N,M;

const int inf = 1001001001;
vector<int> G[max_n];
int S,T;
int dist[max_n][3];

int solve(void) {
    for(int i = 1;i <= N;i++) {
        for(int j = 0;j < 3;j++) {
            dist[i][j] = inf;
        }
    }

    queue<P> q;
    q.push(P(S, 0));
    dist[S][0] = 0;
    while(!q.empty()) {
        int u = q.front().first;
        int l = q.front().second;
        q.pop();
        for(auto v: G[u]) {
            int nl = (l+1)%3;
            if(dist[v][nl] != inf)
                continue;
            dist[v][nl] = dist[u][l]+1;
            q.push(P(v,nl));
        }
    }

    int ans = dist[T][0];
    if(ans == inf)
        return -1;

    return ans/3;
}

int main(void) {
    cin>>N>>M;
    for(int i = 0;i < M;i++) {
        int u,v;
        cin>>u>>v;

        G[u].push_back(v);
    }
    cin>>S>>T;

    cout<<solve()<<endl;

    return 0;
}



