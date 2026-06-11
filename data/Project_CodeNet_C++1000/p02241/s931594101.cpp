#include <iostream>
using namespace std;

#define N 101
#define INF 2010
int n;

int A[N][N];
int color[N];
int d[N];

int mst(int root) {
    int totalW = 0;
    d[root] = 0;

    while(true) {
        int added = -1;
        int minw = INF;
        for (int i = 0; i < n; i++) {
            if (color[i] == 0 && d[i] < minw) {
                added = i;
                minw = d[i];
            }
        }

        if (added == -1) {
            break;
        }

        totalW += minw;
        color[added] = 1;
        for (int i = 0; i < n; i++) {
            if (color[i] == 0 && A[added][i] < d[i]) {
                d[i] = A[added][i];
            }
        }
    }

    return totalW;
}

int main() {
    cin >> n;

    int w;
    for (int i = 0; i < n; i++) {
        color[i] = 0;
        d[i] = INF;
        for (int j = 0; j < n; j++) {
            cin >> w;
            if (w == -1) A[i][j] = INF;
            else A[i][j] = w;
        }
    }

    cout << mst(0) << endl;

    return 0;
}

