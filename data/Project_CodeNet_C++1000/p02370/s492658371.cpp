#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <vector>
#include <stack>
#include <queue>
#include <set>
#include <map>
#include <string>
#include <cmath>
#include <cstdlib>
using namespace std;

const int MAX = 10010;
int V, E;
vector<int> G[MAX];
int dig[MAX];

void init(int V, int E) {
    for (int i = 0; i < V; i++) {
        G[i].clear();
        dig[i] = 0;
    }

    for (int i = 0; i < E; i++) {
        int from, to;
        scanf("%d %d", &from, &to);
        G[from].push_back(to);
        dig[to]++;
    }
}

void topSort(vector<int> &ans) {
    queue<int> Q;
    for (int i = 0; i < V; i++) {
        if (dig[i] == 0) {
            Q.push(i);
        }
    }
    while (!Q.empty()) {
        int t = Q.front();
        Q.pop();
        ans.push_back(t);
        for (int i = 0; i < G[t].size(); i++) {
            int to = G[t][i];
            dig[to]--;
            if (dig[to] == 0) {
                Q.push(to);
            }
        }
    }
}


int main() {
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
    scanf("%d %d", &V, &E);
    init(V, E);
    vector<int> ans;
    topSort(ans);
    for (int i = 0; i < ans.size(); i++) {
        printf("%d\n", ans[i]);
    }
    return 0;
}