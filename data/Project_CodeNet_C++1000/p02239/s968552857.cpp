#include<iostream>
#include<queue>

using namespace std;

int n, M[100][100], d[100];

void bfs (int s) {

    int i, u, v;

    queue<int> Q;
    Q.push(s);
    for (i = 0; i < n; i++) {
        d[i] = (1 << 21);
    }
    d[s] = 0;
    while (!Q.empty()) {
        u = Q.front();
        Q.pop();
        for (v = 0; v < n; v++) {
            if (M[u][v] == 0) {
                continue;
            }
            if (d[v] != (1 << 21)) {
                continue;
            }
            d[v] = d[u] + 1;
            Q.push(v);
        }
    }
    for (i = 0; i < n; i++) {
        cout << i + 1 << " " << ((d[i] == (1 << 21)) ? (-1) : d[i]) << endl;
    }
}

int main () {

    int u, k, v, i, j;

    cin >> n;
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            M[i][j] = 0;
        }
    }

    for (i = 0; i < n; i++) {
        cin >> u >> k;
        u--;
        for (j = 0; j < k; j++){
            cin >> v;
            v--;
            M[u][v] = 1;
        }
    }

    bfs (0);

    return 0;

}