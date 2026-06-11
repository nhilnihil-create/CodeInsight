#include <iostream>
#include <cstdio>
#include <cmath>
#include <vector>
#include <list>
#include <set>
#include <map>
#include <stack>
#include <queue>
#include <string>
#include <utility>
#include <algorithm>
#include <functional>
#include <deque>
#define MAX_V 10000
#define MAX_E 100000

using namespace std;

typedef long long ll;

vector<int> G[MAX_V];
vector<int> ans;
bool done[MAX_V];

void dfs(int i) {
    if (done[i])
        return;
        
    for (int j = 0; j < G[i].size(); ++j) {
        dfs(G[i][j]);
    }
    ans.push_back(i);
    done[i] = true;
}

int main() {
    int V, E;
    cin >> V >> E;
    for (int i = 0; i < E; ++i) {
        int s, t;
        cin >> s >> t;
        G[t].push_back(s);  // 逆向きの辺
    }
    
    for (int i = 0; i < V; ++i) {
        if (done[i])
            continue;
        dfs(i);
    }
    
    for (int i = 0; i < V; ++i) {
        cout << ans[i] << endl;
    }
    
    return 0;
}

