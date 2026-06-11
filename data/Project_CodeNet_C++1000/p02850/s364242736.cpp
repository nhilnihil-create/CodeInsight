#include <bits/stdc++.h>
using namespace std;

#define rp(i, k, n) for (int i = k; i < n; i++)
typedef long long ll;
typedef double ld;



template<class T>inline bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T>inline bool chmin(T &a, const T &b) { if (b<a) { a=b; return 1; } return 0; }
const ll INF = 1ll << 60;
const ll MOD = 1e9 + 7ll;
const double PI=3.14159265358979323846;


int main(){
    int N;
    cin >> N;
    vector < vector <int> > graph(N);
    vector < pair <int, int> > input;
    rp(i, 0, N-1) {
        int a, b;
        cin >> a >> b;
        a--; b--;
        graph[a].emplace_back(b);
        graph[b].emplace_back(a);
        input.emplace_back(a, b);
    }
    map<pair<int, int>, int> color_map;
    vector<int> parent_color(N+1);
    queue<int> q;
    vector<int> reached(N+1);
    int K = 0;
    q.push(0);
    reached[0] = 1;
    while(!q.empty()) {
        int v = q.front(); q.pop();
        int color = 1;
        if(K < graph[v].size()) K = graph[v].size();
        for(auto x: graph[v]) {
            if(reached[x] == 1) continue;
            q.push(x);
            reached[x] = 1;
            if(color == parent_color[v]) color++;
            parent_color[x] = color_map[make_pair(v, x)] = color_map[make_pair(x, v)] = color;
            color++;
        }
    }
    printf("%d\n", K);
    rp(i, 0, N-1) {
        printf("%d\n", color_map[input[i]]);
    }
    return 0;

}