#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;
typedef vector<vector<int>> Graph;
const int dx[4] = {1, 0, -1, 0};
const int dy[4] = {0, 1, 0, -1};
#define pi 3.14159265359
#define inf 2147483647
#define INF 9223372036854775807
#define mod 1000000007
#define mod2 998244353

int main() {
    int N; cin >> N;
    vector<int> a(N - 1), b(N - 1);
    Graph G(N);
    for(int i = 0; i < N - 1; i++) {
        cin >> a[i] >> b[i];
        a[i]--; b[i]--;
        G[a[i]].push_back(b[i]);
        G[b[i]].push_back(a[i]);
    }
    int M = 0, root = -1;
    for(int i = 0; i < N; i++) {
        if(M < G[i].size()) {
            M = G[i].size();
            root = i;
        }
    }
    queue<int> q;
    q.push(root);
    vector<int> visit(N);
    visit[root] = 1;
    map<pair<int, int>, int> edge;
    vector<set<int>> color(N);
    while(!q.empty()) {
        int u = q.front(); q.pop();
        int c = 1;
        for(auto v: G[u]) {
            if(visit[v] != 0) continue;
            visit[v] = 1;
            pair<int, int> w(u, v), x(v, u);
            while(color[u].count(c) || color[v].count(c)) c++;
            edge[w] = c; edge[x] = c;
            color[u].insert(c); color[v].insert(c); 
            q.push(v);
            c++;
        }
    }
    cout << M << endl;
    for(int i = 0; i < N - 1; i++) {
        pair<int, int> p(a[i], b[i]);
        cout << edge[p] << endl;
    }
    return 0;
}