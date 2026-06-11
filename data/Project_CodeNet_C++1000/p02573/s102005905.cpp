/**
 *    author:  Taichicchi
 *    created: 21.09.2020 08:57:17
 **/

#include <bits/stdc++.h>

#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

#define rep(i, n) for (int i = 0; i < (int)(n); i++)
typedef long long ll;

struct UnionFind {
    vector<int> r;

    UnionFind(int N) { r = vector<int>(N, -1); }

    bool unite(int a, int b) {
        a = find(a);
        b = find(b);
        if (a == b) return false;
        if (r[a] > r[b]) swap(a, b);
        r[a] += r[b];
        r[b] = a;
        return true;
    }

    int find(int a) {
        if (r[a] < 0) return a;
        return r[a] = find(r[a]);
    }

    int size(int a) { return -r[find(a)]; }
};

int main() {
    int N, M;
    cin >> N >> M;

    UnionFind uf(N);

    rep(i, M) {
        int A, B;
        cin >> A >> B;
        A--;
        B--;
        uf.unite(A, B);
    }

    int ans = 0;
    rep(i, N) { ans = max(ans, uf.size(i)); }
    cout << ans << endl;

    return 0;
}