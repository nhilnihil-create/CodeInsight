#include <bits/stdc++.h>
using namespace std;
int N;
int a[500][500] = {};

void solve(int l, int r, int level) {
    int m = (l + r) / 2;
    if(r - l == 1) return;
    for(int i=l; i<m; ++i) {
        for(int j=m; j<r; ++j) a[i][j] = level;
    }
    solve(l, m, level + 1);
    solve(m, r, level + 1);
}

void print() {
    for(int i=0; i<N; ++i) {
        for(int j=i+1; j<N; ++j) {
            cout << a[i][j] << (j + 1 == N ? '\n' : ' ');
        }
    }
}

int main() {
    cin >> N;
    solve(0, N, 1);
    print();
    return 0;
}