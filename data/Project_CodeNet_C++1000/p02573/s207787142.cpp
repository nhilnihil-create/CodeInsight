#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

#include <iostream>
#include <vector>

using namespace std;

struct UnionFind
{
    vector<int> par;

    void init(int N) { par.assign(N, -1); }

    int root(int x)
    {
        if (par[x] < 0) { return x; }              // x が根
        else { return par[x] = root(par[x]); }     // 経路短縮
    }

    bool same(int x, int y) { return (root(x) == root(y)); }

    void unite(int x, int y)
    {
        int xx = root(x);
        int yy = root(y);

        if (xx == yy) { return; }

        if (par[xx] < par[yy])
        {
            par[xx] += par[yy];
            par[yy] = xx;
        }
        else
        {
            par[yy] += par[xx];
            par[xx] = yy;
        }
    }

    int size(int x)
    {
        return -par[root(x)];
    }
};


int main()
{
    int N, M;
    UnionFind uf;

    cin >> N >> M;
    uf.init(N);
    for (int i = 0; i < M; ++i) 
    { 
        int a, b;
        cin >> a >> b;
        a--;
        b--;
        uf.unite(a, b);
    }

    cout << (-*min_element(uf.par.begin(), uf.par.end())) << endl;


    return 0;
}
