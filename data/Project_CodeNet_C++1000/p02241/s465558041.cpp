#include <iostream>
#include <vector>
#include <climits>

using namespace std;

const int kSize = 100001;

vector<int> V;

struct Node {
    int to;
    int weight;

    Node(int _to, int _weight) {
        to = _to;
        weight = _weight;
    }
};

int n;
vector<Node> adj[kSize];
bool isMarked[kSize];
int tree[kSize];
int ans = 0;

pair<int,int> GetMinWeight(int v) {
    int ans = INT_MAX;
    int vertex = -1;
    for (int i = 0; i < adj[v].size(); ++i) {
        int u = adj[v][i].to;
        if (!isMarked[u]) {
            //ans = min(ans, adj[v][i].weight);
            //vertex = u;
            if (adj[v][i].weight <= ans) {
                ans = adj[v][i].weight;
                vertex = u;
            }
        }
    }

    ans = ans == INT_MAX ? -1 : ans;
    return make_pair(ans, vertex);
}

int GetMinVertex() {
    int v = -1;
    int min = INT_MAX;
    for (int i = 0; i < V.size(); ++i) {
        pair<int, int> p = GetMinWeight(V[i]);
        int weight = p.first;
        if (weight != -1 && weight <= min) {
            min = weight;
            v = p.second;
        }
    }

    ans += min;
    return v;
}

int Prime() {
    V.push_back(1);
    isMarked[1] = true;

    while (V.size() < n) {
        int v = GetMinVertex();
        //cout << v << endl;
        V.push_back(v);
        isMarked[v] = true;
    }
}

int main() {
    fill(isMarked, isMarked + kSize, false);
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n; ++j) {
            int weight;
            cin >> weight;
            if (weight != -1) {
                adj[i].emplace_back(j, weight);
            }
        }
    }

    Prime();
    cout << ans << endl;
}
