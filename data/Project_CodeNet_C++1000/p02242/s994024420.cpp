#include <iostream>
#include <vector>
#include <climits>
#include <queue>

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
int dis[kSize];

void Dijkstra(int s) {
    dis[s] = 0;
    priority_queue<pair<int, int>, vector<pair<int, int> >, greater<> > pq;

    pq.push(make_pair(s, 0));
    isMarked[s] = true;
    tree[s] = s;

    while (!pq.empty()) {
        pair<int, int> p = pq.top();
        pq.pop();
        int from = p.first;
        for (int i = 0; i < adj[from].size(); ++i) {
            int to = adj[from][i].to;
            if (!isMarked[to]) {
                if (dis[from] + adj[from][i].weight < dis[to]) {
                    dis[to] = dis[from] + adj[from][i].weight;
                    tree[to] = from;
                    pq.push(make_pair(to, dis[to]));
                }
            }
        }
    }
}

int main() {
    fill(isMarked, isMarked + kSize, false);
    fill(dis, dis + kSize, INT_MAX);
    cin >> n;
    for (int i = 0; i < n; ++i) {
        int u, k;
        cin >> u >> k;
        for (int j = 0; j < k; ++j) {
            int v, c;
            cin >> v >> c;
            adj[u].emplace_back(v, c);
        }
    }

    Dijkstra(0);
    for (int i = 0; i < n; ++i) {
        cout << i << " " << dis[i] << endl;
    }
}
