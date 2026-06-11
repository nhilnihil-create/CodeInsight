#include <iostream>
#include <vector>

using namespace std;

#define INF (1 << 30)

struct Node {
    int id;
    int cost;
    vector<int> next_node;
    vector<int> next_cost;
} node[1000];

int main() {
    int v, e, r, s, t, d;

    cin >> v >> e >> r;
    for (int i = 0; i < v; i++) {
        node[i].id = i;
        node[i].cost = INF;
    }
    for (int i = 0; i < e; i++) {
        cin >> s >> t >> d;
        node[s].next_node.push_back(t);
        node[s].next_cost.push_back(d);
    }

    int count = 0;
    bool update, next[v] = { false };
    next[r] = true;
    node[r].cost = 0;
    while (1) {
        if (count >= v) {
            cout << "NEGATIVE CYCLE\n";
            return 0;
        }
        update = false;
        for (int i = 0; i < v; i++) {
            if (next[i] == false) {
                continue;
            }
            int size = node[i].next_node.size();
            for (int j = 0; j < size; j++) {
                int to = node[i].next_node[j];
                next[to] = true;
                if (node[to].cost > node[i].cost + node[i].next_cost[j]) {
                    node[to].cost = node[i].cost + node[i].next_cost[j];
                    update = true;
                }
            }
        }
        if (update == false) {
            break;
        }
        count++;
    }
    for (int i = 0; i < v; i++) {
        if (next[i] == false) {
            cout << "INF\n";
        }
        else {
            cout << node[i].cost << endl;
        }
    }

    return 0;
}