#include<iostream>

using namespace std;

int par[10000];
int rank[10000];
void init(int n) {
    for (int i = 0; i < n; i++) {
        par[i] = i;
        rank[i] = 0;
    }
}
int find(int x) {
    if (par[x] == x) {
        return x;
    }
    else {
        return par[x] = find(par[x]);
    }
}
void unite(int x, int y) {
    x = find(x);
    y = find(y);
    if (x == y)return;
    par[x] = y;
}
bool same(int x, int y) {
    return find(x) == find(y);
}
int main()
{
    int n;
    long q;
    cin >> n >> q;
    init(n);
    for (int i = 0; i < q; i++) {
        int com, x, y;
        cin >> com >> x >> y;
        if (com == 0) unite(x, y);
        else if (com == 1) {
            if (same(x, y))cout << "1\n";
            else cout << "0\n";
        }
    }
    return 0;
}