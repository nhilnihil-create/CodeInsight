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

const int max_n = 1000+10;
const int max_v = max_n*max_n/2;

int N;
int id[max_n][max_n];
vector<int> to[max_v];

int toId(int i,int j) {
    if(i > j)
        swap(i,j);

    return id[i][j];
}

bool visited[max_v];
bool calc[max_v];
int dp[max_v]; //max length of path from v

int dfs(int v) {
    if(visited[v]) {
        if(!calc[v])
            return -1;
        return dp[v];
    }

    visited[v] = true;
    dp[v] = 1;

    for(auto u: to[v]) {
        int res = dfs(u);
        if(res == -1)
            return -1;
        dp[v] = max(dp[v], res+1);
    }

    calc[v] = true;
    return dp[v];
}

int main(void) {
    cin>>N;

    vector<vector<int>> A(N, vector<int>(N-1));
    for(int i = 0;i < N;i++) {
        for(int j = 0;j < N-1;j++) {
            cin>>A[i][j];
            A[i][j]--;
        }
    }

    int V = 0;
    for(int i = 0;i < N;i++) {
        for(int j = 0;j < N;j++) {
            if(i < j)
                id[i][j] = V++;
        }
    }

    for(int i = 0;i < N;i++) {
        for(int j = 0;j < N-1;j++) {
            A[i][j] = toId(i,A[i][j]);
        }
        for(int j = 0;j < N-2;j++) {
            to[A[i][j+1]].push_back(A[i][j]);
        }
    }

    int ans = 0;
    for(int i = 0;i < V;i++) {
        int res = dfs(i);
        if(res == -1) {
            cout<<-1<<endl;

            return 0;
        }
        ans = max(ans,res);
    }

    cout<<ans<<endl;

    return 0;
}
