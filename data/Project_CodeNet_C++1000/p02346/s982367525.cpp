#include<iostream>
#include<algorithm>
using namespace std;
const int maxn = 400001;
const int INF = 0x7fffffff;
struct SegTree
{
    int id;
    int left, right;
    int minv;
    int sum;
};


SegTree stree[maxn];
int A[maxn];

void build(int v, int l, int r)
{
    stree[v].left = l;
    stree[v].right = r;
    if(l == r)
    {
        stree[v].sum = A[l];
        stree[v].minv = A[l];
    }
    else
    {
        int mid = (l + r) / 2;
        build(2 * v, l, mid);
        build(2 * v + 1, mid + 1, r);
        stree[v].sum = stree[v*2].sum + stree[v*2+1].sum;
        stree[v].minv = min(stree[v*2].minv, stree[v*2+1].minv);
    }
}

int findSum(int root, int l, int r)
{
    if(stree[root].left >= l && stree[root].right <= r)
    {
        return stree[root].sum;
    }
    else
    {
        int sumL = 0, sumR = 0;
        int mid = (stree[root].left + stree[root].right) / 2;
        if(l <= mid)
            sumL = findSum(root * 2, l, r);
        if(r > mid)
            sumR = findSum(root * 2 + 1, l, r);
        return sumL + sumR;
    }
}

void update(int id, int pos, int x)
{
    if(stree[id].left == stree[id].right)
    {
        A[stree[id].left] += x;
        stree[id].minv += x;
        stree[id].sum += x;
    }
    else
    {
        int mid = (stree[id].left + stree[id].right) / 2;
        if(pos <= mid) update(id * 2, pos, x);
        else update(id * 2 + 1, pos, x);
        stree[id].sum = stree[id*2].sum + stree[id*2+1].sum;
        stree[id].minv = min(stree[id*2].minv, stree[id*2+1].minv);
    }
}

int main()
{
    int n, q;
    cin >> n >> q;
    for(int i = 1; i <= n; i++)
        A[i] = 0;
    build(1, 1, n);

    for(int i = 0; i < q; i++)
    {
        int com, pos, v;
        cin >> com >> pos >> v;
        if(com == 0) update(1, pos, v);
        else if(com == 1) cout << findSum(1, pos, v) << endl;
    }

    return 0;

}

