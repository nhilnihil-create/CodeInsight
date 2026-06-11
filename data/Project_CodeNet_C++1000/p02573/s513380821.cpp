#include <bits/stdc++.h>
#define endl '\n'
#define rep(i, s, e) for (int i = s; i < e; i++)
using namespace std;

struct UnionFind
{
    vector<int> par; // par[i]:iの親の番号　(例) par[3] = 2 : 3の親が2

    UnionFind(int N) : par(N)
    { //最初は全てが根であるとして初期化
        for (int i = 0; i < N; i++)
            par[i] = -1;
    }

    int root(int x)
    { // データxが属する木の根を再帰で得る：root(x) = {xの木の根}
        if (par[x] < 0)
            return x;
        return par[x] = root(par[x]);
    }

    int size(int x)
    {
        return -par[root(x)];
    }

    void unite(int x, int y)
    {                    // xとyの木を併合
        int rx = root(x); //xの根をrx
        int ry = root(y); //yの根をry
        if (rx == ry)
            return; //xとyの根が同じ(=同じ木にある)時はそのまま
        if (size(rx) < size(ry))
        {
            swap(rx, ry);
        }
        par[rx] += par[ry];
        par[ry] = rx;
    }

    bool same(int x, int y)
    { // 2つのデータx, yが属する木が同じならtrueを返す
        int rx = root(x);
        int ry = root(y);
        return rx == ry;
    }
};
int main()
{
    int N, M;
    cin >> N >> M;
    UnionFind A(N);
    rep(i, 0, M)
    {
        int a, b;
        cin >> a >> b;
        A.unite(a, b);
    }
    int res = 0;
    rep(i, 0, N)
    {
        res = max(res, A.size(i));
    }
    cout << res << endl;
}
