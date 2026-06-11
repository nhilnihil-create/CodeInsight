#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#include <string>
#include <numeric>
#include <cstring>
#include <cmath>
#include <list>

const int MOD = 1e9 + 7;
const int MAX = 100000;
#define rep(i, n) for (int i = 0; i < (n); i++)

using ll = long long int;
using namespace std;

vector<int> graph[MAX];
list<int> out;
bool visited[MAX];
int N, M, cnt = 0;

void dfs(int u)
{
    visited[u] = true;
    for (int i = 0; i < graph[u].size(); i++)
    {
        int v = graph[u][i];
        if (!visited[v])
            dfs(v);
    }

    out.push_front(u);
}

int main()
{
    cin >> N >> M;
    for (int i = 0; i < M; i++)
    {
        int s, t;
        cin >> s >> t;
        graph[s].push_back(t);
    }

    for(int i = 0; i < N; i++)
        visited[i] = false;

    for (int i = 0; i < N; i++)
        if (!visited[i])
            dfs(i);

    for(auto x : out)
        cout << x << endl;

    return 0;
}
