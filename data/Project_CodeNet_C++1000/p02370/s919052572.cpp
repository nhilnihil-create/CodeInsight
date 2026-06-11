#include <iostream>
#include <vector>
#include <queue>
using namespace std;

#define N 10001
vector<int> A[N];
vector<int> sorted;
int color[N];
int indeg[N];

void topologicalsort(int root) {
    queue<int> Q;
    Q.push(root);
    color[root] = 1;
    while (!Q.empty()) {
        int node = Q.front();
        Q.pop();
        sorted.push_back(node);
        for (vector<int>::iterator it=A[node].begin(); it != A[node].end(); it++) {
            indeg[*it]--;
            if (color[*it] == 0 && indeg[*it] == 0) {
                color[*it] = 1;
                Q.push(*it);
            }
        }
    }
}

int main() {
    int n, e;
    cin >> n >> e;

    for (int i = 0; i < n; i++) {
        color[i] = 0;
        indeg[i] = 0;
    }

    int v1, v2;
    for (int i = 0; i < e; i++) {
        cin >> v1 >> v2;
        A[v1].push_back(v2);
        indeg[v2]++;
    }

    for (int i = 0; i < n; i++) {
        if (color[i] == 0 && indeg[i] == 0) {
            topologicalsort(i);
        }
    }

    for (int i = 0; i < sorted.size(); i++) {
        cout << sorted[i] << endl;
    }

    return 0;
}
