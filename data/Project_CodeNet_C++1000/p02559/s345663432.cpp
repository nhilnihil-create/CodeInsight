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


template<class T> class BIT   // 1-indexed (0 is not used)
{
private:
    int num;
    vector<T> bit;
public:
    BIT(int n) :bit(vector<T>(n + 1, 0)), num(n) {}

    T sum(int i) {   // sum of 1..i
        if (!i) return 0;
        return bit[i] + sum(i - (i&-i));
    }

    void add(int i, T x) {
        if (i > num) return;
        bit[i] += x;
        add(i + (i&-i), x);
    }

    int lower_bound(T x) {
        T res = 0;
        int N = 1;
        while (N < num) N *= 2;
        int i;
        for (i = N / 2; i > 0; i /= 2) {
            if (res + i < num && bit[res + i] < x) {
                x = x - bit[res + i];
                res = res + i;
            }
        }
        return res + 1;
    }
};

void solve()
{
    int n, Q;
    scanf("%d%d", &n, &Q);
    BIT<ll> bit(n);
    int i;
    for (i = 0; i < n; i++) {
        int tmp;
        scanf("%d", &tmp);
        bit.add(i + 1, tmp);
    }
    
    for (i = 0; i < Q; i++) {
        int t, u, v;
        scanf("%d%d%d", &t, &u, &v);
        if (t == 0) {
            bit.add(u + 1, v);
        }
        else {
            printf("%lld\n", bit.sum(v) - bit.sum(u));
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

