//
// Created by tattsun on 2017/02/16.
//

#include <iostream>

#define MAX_N 101
#define NIL -1
#define INFTY 1000000
#define TOTAL_INFTY INFTY*MAX_N

using namespace std;

enum Status {
    White,
    Gray,
    Black,
};

int n;
int w[MAX_N][MAX_N];
int d[MAX_N], parent[MAX_N];
Status st[MAX_N];

int min(int x, int y) {
    if(x < y) return x;
    return y;
}

void dijkstra() {
    for(int i=0; i<n; i++) {
        d[i] = TOTAL_INFTY;
        st[i] = White;
        parent[i] = NIL;
    }

    int p = 0;
    d[p] = 0;

    while(true) {
        if(p == -1) break;
        st[p] = Black;

        for(int i=0; i<n; i++) {
            if(w[p][i] != TOTAL_INFTY && st[i] != Black) {
                d[i] = min(d[i], d[p] + w[p][i]);
                st[i] = Gray;
            }
        }

        p = -1;
        int c = TOTAL_INFTY;
        for(int i=0; i<n; i++) {
            if(st[i] == Gray && d[i] < c) {
                p = i;
                c = d[i];
            }
        }
    }
}

int main() {
    for(int i=0; i<MAX_N; i++) {
        for (int j = 0; j < MAX_N; j++) {
            w[i][j] = TOTAL_INFTY;
        }
    }

    cin >> n;

    int u, k, v, c;
    for(int i=0; i<n; i++) {
        cin >> u >> k;
        for(int j=0; j<k; j++) {
            cin >> v >> c;
            w[u][v] = c;
        }
    }

    dijkstra();

    for(int i=0; i<n; i++) {
        cout << i << " " << d[i] << endl;
    }
}