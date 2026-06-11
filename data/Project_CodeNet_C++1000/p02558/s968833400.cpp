#include <cstdio>
#include <string>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <stack>
#include <list>
#include <iterator>
#include <cassert>
#include <numeric>
#include <functional>
#include <time.h>
#pragma warning(disable:4996) 

typedef long long ll;
typedef unsigned long long ull;
#define MIN(a, b) ((a)>(b)? (b): (a))
#define MAX(a, b) ((a)<(b)? (b): (a))
#define LINF  9223300000000000000
#define LINF2 1223300000000000000
#define LINF3 1000000000000
#define INF 2140000000
const long long MOD = 1000000007;
//const long long MOD = 998244353;

using namespace std;

class UF
{
private:
    int         num;
    vector<int> par;
    vector<int> siz;
public:
    //vector<int> val;
public:
    UF(int n) : num(n) {
        par.resize(n);
        siz.resize(n);
        //val.resize(n);
        int i;
        for (i = 0; i < n; i++) {
            par[i] = i; siz[i] = 1;
            //val[i]=0;
        }
    }

    int find(int x) {
        if (x == par[x]) return x;
        return par[x] = find(par[x]);
    }

    void unite(int x, int y) {
        x = find(x);
        y = find(y);
        if (x == y) return;
        if (siz[x] < siz[y]) {
            par[x] = y;
            siz[y] = siz[x] + siz[y];
            //val[y]=val[x]+val[y];
        }
        else {
            par[y] = x;
            siz[x] = siz[x] + siz[y];
            //val[x]=val[x]+val[y];
        }
    }

    bool same(int x, int y) {
        return find(x) == find(y);
    }

    int size(int x) {
        return siz[find(x)];
    }

    int ngroup() {
        //int ngroup( int& ans ) {
        int count = 0;
        int i;
        for (i = 0; i < num; i++) {
            if (par[i] == i) {
                count++;
                //ans += (val[i]? siz[i]: siz[i]-1);
            }
        }
        return count;
    }
};

void solve()
{
    int n, Q;
    scanf("%d%d", &n, &Q);

    UF uf(n);
    int i;
    for (i = 0; i < Q; i++) {
        int t, u, v;
        scanf("%d%d%d", &t, &u, &v);
        if (t == 0) {
            uf.unite(u, v);
        }
        else {
            if (uf.same(u, v)) {
                printf("1\n");
            }
            else {
                printf("0\n");
            }
        }
    }

    return;
}

int main()
{
#if 1
    solve();
#else
    int T;
    scanf("%d", &T);
    int t;
    for (t = 0; t < T; t++) {
        //printf("Case #%d: ", t + 1);
        solve();
    }
#endif
    return 0;
}

