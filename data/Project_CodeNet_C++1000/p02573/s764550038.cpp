// 
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cstdlib>
#include <vector>
#include <string>
#include <algorithm>
#include <numeric>
#include <map>
#include <unordered_map>
#include <stack>
#include <queue>
#include <set>
#include <unordered_set>
#include <bitset>
using namespace std;
using ll = long long;
using P = pair<ll, ll>;
#define REP(i, n) for(size_t i = 0; i < (n); ++i)

struct UnionFind
{
    std::vector<int> par; // par[a] = b ... a の親は b であるという意味. 根の場合は木の成分数に(-1)をかけた値.
    UnionFind(int n) : par(n, -1){} // 親なし(-1)として初期化

    // x の根を返す
    int root(int x)
    {
        // 親がいない場合 x 自身が根
        if (par[x] < 0) return x;
        // 親がいる場合はその親を辿り、再帰的に根を求める
        else return par[x] = root(par[x]);
    }

    // x と y が同じ木に属しているかどうか
    bool isSame(int x, int y)
    {
        return root(x) == root(y);
    }

    // x が属している木と y が属している木の結合
    void merge(int x, int y)
    {
        int rx = root(x), ry = root(y);
        if (rx == ry) return; // 既に結合しているため
        
        if (par[rx] > par[ry]) std::swap(x, y);
        par[rx] += par[ry]; // 深さを更新
        par[ry] = rx;       // x の根 rx に y の根 ry を結合 

    }

    // x が属する木の深さを返す
    int size(int x)
    {
        return -par[root(x)];
    }
};


int main()
{
    int N, M;
    cin >> N >> M;
    vector<int> A(M), B(M);
    REP(i, M)
    {
        cin >> A[i] >> B[i];
        --A[i], --B[i];
    }
    int ans = 0;
    UnionFind uf(N);
    REP(i, M)
    {
        if (!uf.isSame(A[i], B[i]))
            uf.merge(A[i], B[i]);
    }
    REP(i, N)
    {
        ans = max(ans, uf.size(i));
    }
    cout << ans << endl;
    return 0;
}
