#include "bits/stdc++.h"

using namespace std;
int main(void){
    int N;
    int dx[] = {-1, 0, 1, 0};
    int dy[] = {0, -1, 0, 1};
    while (cin >> N && N) {
        int x[N] = {0};
        int y[N] = {0};
        int t = 0, l = 0, r = 0, b = 0;
        for (int i = 1; i < N; ++i) {
            int n, d;
            cin >> n >> d;
            x[i] = x[n] + dx[d];
            y[i] = y[n] + dy[d];
            t = max(t, y[i]);
            l = min(l, x[i]);
            r = max(r, x[i]);
            b = min(b, y[i]);
        }
        cout << (r - l + 1) << " " << (t - b + 1) << endl;
    }
    return EXIT_SUCCESS;
}