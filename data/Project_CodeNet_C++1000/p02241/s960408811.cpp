//
// Created by tattsun on 2017/02/16.
//

#include <iostream>

#define MAX_N 101
#define INFTY 20000
#define NIL -1

enum Color {
    White,
    Glay,
    Black,
};

using namespace std;

int n;
int w[MAX_N][MAX_N];
int d[MAX_N], p[MAX_N];
Color color[MAX_N];

int min(int x, int y) {
    if(x < y) return x;
    return y;
}

int solve() {
    d[0] = 0;

    while(true) {
        int u = NIL, c = INFTY;

        for(int i=0; i<n; i++) {
            if(d[i] < c && color[i] != Black) {
                u = i;
                c = d[i];
            }
        }

        if(u == NIL)
            break;

        color[u] = Black;

        for(int i=0; i<n; i++) {
            if(color[i] != Black && w[u][i] != INFTY) {
                if(d[i] > w[u][i]) {
                    d[i] = w[u][i];
                    p[i] = u;
                    color[i] = Glay;
                }
            }
        }
    }


    int tc = 0;
    for(int i=0; i<n; i++) {
        if(p[i] != NIL)
            tc += w[i][p[i]];
    }
    return tc;
}

int main() {
    for (int i = 0; i < MAX_N; i++) {
        d[i] = INFTY;
        p[i] = NIL;
        color[i] = White;
        for (int j = 0; j < MAX_N; j++)
            w[i][j] = INFTY;
    }

    int p;
    cin >> n;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> p;
            w[i][j] = (p == -1) ? INFTY : p;
        }
    }

    cout << solve() << endl;
}