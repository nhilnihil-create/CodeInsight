#pragma GCC target("avx")
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#include <bits/stdc++.h>
using namespace std;
static const int rdata_sz = (1 << 22), wdata_sz = (1 << 22);
char rdata[rdata_sz], wdata[wdata_sz], *rb, *wb;
struct FastIO
{
    FastIO()
    {
        fread(rdata, 1, rdata_sz, stdin);
        rb = rdata;
        wb = wdata;
    }
    ~FastIO()
    {
        fwrite(wdata, 1, wb - wdata, stdout);
    }
    template <typename T>
    inline void read(T &x)
    {
        bool neg = false;
        x = 0;
        while ((*rb < '0' || *rb > '9') && *rb != '-')
            ++rb;
        while ('0' <= *rb && *rb <= '9')
        {
            x = 10 * x + (*rb - '0');
            ++rb;
        }
        if (neg)
            x = -x;
    }
};
#define pc(x) *(wb++) = x
int par[500001];
int ran[500001];
//要素xが所属する木の根を再帰的に発見する
inline int root(int x)
{
    if (par[x] == x)
        return x;
    return par[x] = root(par[x]); //経路圧縮
}
//要素xが属する木と要素yが属する木の併合
inline void unite(int x, int y)
{
    int rx = root(x);
    int ry = root(y);
    if (rx == ry)
        return; //同じ木に属してたらそのまま
    if (ran[rx] < ran[ry])
    {
        par[rx] = ry; //根がryの木に併合
    }
    else
    {
        par[ry] = rx; //根がrxの木に併合
        if (ran[rx] == ran[ry])
            ran[rx]++;
    }
}
//要素xが属する木と要素yが属する木が同じならtrueを返す
inline bool same(int x, int y)
{
    return root(x) == root(y);
}
int main()
{
    FastIO io;
    int N, Q;
    io.read(N);
    io.read(Q);
    for (int i = 0; i < N; i++)
    {
        par[i] = i;
        ran[i] = 0;
    }
    for (int i = 0; i < Q; i++)
    {
        int a, b, c;
        io.read(a);
        io.read(b);
        io.read(c);
        if (a == 1)
            if (same(b, c)){
              pc('1');
              pc(' ');
            }
            else{
              pc('0');
              pc(' ');
            }
        if (a == 0)
            unite(b, c);
    }
    return 0;
}
