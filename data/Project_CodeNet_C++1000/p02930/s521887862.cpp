#include <bits/stdc++.h>
using namespace std;
using lint = long long int;

int edges[512][512];

// 頂点[left, right)に辺を張る
void add_edge(int left, int right, int level) {
    if(right - left == 1) return;
    int mid = (left+right)/2;
    add_edge(left, mid, level+1);
    add_edge(mid, right, level+1);

    for(int i=left; i<mid; i++)
    for(int j=mid; j<right; j++) {
        edges[i][j] = level;
        edges[j][i] = level;
    }
}

int main() {
    lint n;
    cin >> n;

    add_edge(0, n, 1);
    for(int i=0; i<n-1; i++) {
        for(int j=i+1; j<n; j++) {
            cout << edges[i][j] << " ";
        }
        cout << endl;
    }
}