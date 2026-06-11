#include <iostream>
#include <cstdio>
#include <cmath>
#include <string>
#include <cstring>
#include <algorithm>
#include <limits>
#include <vector>
#include <stack>
#include <queue>
#include <set>
#include <map>
#include <unordered_map>
#include <unordered_set>
#define lowbit(x) ( x&(-x) )
#define pi 3.141592653589793
#define e 2.718281828459045
#define INF 0x3f3f3f3f
#define eps 1e-6
#define HalF (l + r)>>1
#define lsn rt<<1
#define rsn rt<<1|1
#define Lson lsn, l, mid
#define Rson rsn, mid+1, r
#define QL Lson, ql, qr
#define QR Rson, ql, qr
#define myself rt, l, r
using namespace std;
typedef unsigned long long ull;
typedef unsigned int uit;
typedef long long ll;
const int maxN = 1e5 + 7;
int N, a[maxN], pre[maxN][2][2] = {0};
int t[2][maxN<<2];
inline void pushup(int *tree, int rt) { tree[rt] = max(tree[lsn], tree[rsn]); }
void update(int *tree, int rt, int l, int r, int qx, int val)
{
    if(l == r) { tree[rt] = val; return; }
    int mid = HalF;
    if(qx <= mid) update(tree, Lson, qx, val);
    else update(tree, Rson, qx, val);
    pushup(tree, rt);
}
inline int query(int *tree, int rt, int l, int r, int ql, int qr)
{
    if(ql <= l && qr >= r) return tree[rt];
    int mid = HalF;
    if(qr <= mid) return query(tree, QL);
    else if(ql > mid) return query(tree, QR);
    else return max(query(tree, QL), query(tree, QR));
}
ll ans = 0;
inline void solve(int id)
{
    int l = 1, r = id - 1, mid = 0, ith = 0;
    while(l <= r)
    {
        mid = (l + r)>>1;
        if(query(t[0], 1, 1, N, mid, id - 1) > a[id])
        {
            l = mid + 1;
            ith = mid;
        }
        else r = mid - 1;
    }
    if(ith == 0) return;
    pre[id][0][0] = ith;
    l = 1; r = ith - 1; ith = 0;
    int nex_id = r;
    while(l <= r)
    {
        mid = (l + r)>>1;
        if(query(t[0], 1, 1, N, mid, nex_id) > a[id])
        {
            l = mid + 1;
            ith = mid;
        }
        else r = mid - 1;
    }
    if(ith == 0) return;
    pre[id][0][1] = ith;
}
inline void finsh(int id)
{
    int l = id + 1, r = N, mid = 0, ith = 0;
    while(l <= r)
    {
        mid = (l + r)>>1;
        if(query(t[1], 1, 1, N, id + 1, mid) > a[id])
        {
            r = mid - 1;
            ith = mid;
        }
        else l = mid + 1;
    }
    if(ith == 0) return;
    pre[id][1][0] = ith;
    l = ith + 1; r = N; ith = 0;
    int nex_id = l;
    while(l <= r)
    {
        mid = (l + r)>>1;
        if(query(t[1], 1, 1, N, nex_id, mid) > a[id])
        {
            r = mid - 1;
            ith = mid;
        }
        else l = mid + 1;
    }
    if(ith == 0) return;
    pre[id][1][1] = ith;
}
int main()
{
    scanf("%d", &N);
    for(int i=1; i<=N; i++) scanf("%d", &a[i]);
    for(int i=1; i<=N; i++) pre[i][1][1] = pre[i][1][0] = N + 1;
    update(t[0], 1, 1, N, 1, a[1]);
    for(int i=2; i<=N; i++)
    {
        solve(i);
        update(t[0], 1, 1, N, i, a[i]);
    }
    update(t[1], 1, 1, N, N, a[N]);
    for(int i=N-1; i>=1; i--)
    {
        finsh(i);
        update(t[1], 1, 1, N, i, a[i]);
    }
    for(int i=1; i<=N; i++)
    {
        ans += 1LL * (pre[i][0][0] - pre[i][0][1]) * (pre[i][1][0] - i) * a[i];
        ans += 1LL * (i - pre[i][0][0]) * (pre[i][1][1] - pre[i][1][0]) * a[i];
    }
    printf("%lld\n", ans);
    return 0;
}