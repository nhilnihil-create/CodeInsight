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

int N;
Int K;
const int max_n = 100000+10;
vector<int> G[max_n];
bool visited[max_n];

Int dfs(int u, int p) {
    Int color;
    if(p == -1)
        color = K-1;
    else
        color = K-2;
    
    if(K < G[u].size())
        return 0;

    Int case_num = 1;
    for(auto v: G[u]) {
        if(v == p)
            continue;
        case_num = (case_num*color)%MOD;
        color--;
    }

    for(auto v: G[u]) {
        if(v == p)
            continue;
        case_num = (case_num*dfs(v, u))%MOD;
    }
    
    return case_num;
}

int main(void) {
    cin>>N>>K;

    for(int i = 0;i < N-1;i++) {
        int a,b;
        cin>>a>>b;
        a--;
        b--;
        G[a].push_back(b);
        G[b].push_back(a);
    }

    Int ans = dfs(0, -1)*K%MOD;
    cout<<ans<<endl;

    return 0;
}
