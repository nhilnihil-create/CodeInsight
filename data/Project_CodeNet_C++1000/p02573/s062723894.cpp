#include <bits/stdc++.h> 
using namespace std;

struct UnionFind {
    vector<int> r;

    UnionFind(int N) {
        r = vector<int>(N, -1);
    }

    int root(int x) {
        if (r[x] < 0) return x;
        return r[x] = root(r[x]);
    }

    bool unite(int x, int y) {
        int rx = root(x);
        int ry = root(y);
        
        if (rx == ry) return false;
        if(r[rx] > r[ry]) swap(rx, ry);
        r[rx] += r[ry];
        r[ry] = rx;
        return true;
    }

    int size(int x) {
        return -r[root(x)];
    }

    bool same(int x, int y) {
        return root(x) == root(y); 
    }
};

int main() {
    int N, M;
    cin >> N >> M;
    UnionFind UF(N);
    int A, B;
    for(int i = 0; i < M; i++) {
        cin >> A >> B;
        A -= 1;
        B -= 1;
        UF.unite(A, B);
    }
    
    int ans = 0;
    for(int i = 0; i < N; i++) {
        //cout << i << ": " << UF.r[i] << endl;
        ans = max(UF.size(i), ans);
    }

    cout << ans << endl;
}