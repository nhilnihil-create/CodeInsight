#include <bits/stdc++.h>
#include <numeric>
#define REP(i, s, n) for (int i = s; i < n; ++i)
#define rep(i, n) REP(i, 0, n)
#define SORT(c) sort((c).begin(), (c).end())
#define SORT_INV(c) sort((c).begin(), (c).end(), greater<int>())
#define IINF INT_MAX
#define LLINF LLONG_MAX
#define DEBUG true
#define LL long long
#define Num 1000000007
// sort(a.begin(), a.end(), std::greater<int>());
using namespace std;

int main()
{
    int n;
    cin >> n;
    int a[n][n] = {0};
    rep(i, n)
    {
        rep(j, n)
        {
            int temp;
            cin>>temp;
            if(temp==-1) temp=INT_MAX;
            a[i][j]=temp;
        }
    }
    int mincost[n];
    bool used[n];
    rep(i, n)
    {
        mincost[i] = INT_MAX;
        used[i] = false;
    }
    //solve by prim
    mincost[0] = 0;
    int res = 0;
    while (true)
    {
        int v = -1;
        rep(i, n)
        {
            if (used[i] == false && (v == -1 || mincost[i] < mincost[v]))
                v = i;
        }
        if (v == -1)
            break;
        used[v] = true;
        res += mincost[v];
        rep(i, n)
        {
            mincost[i] = min(mincost[i], a[v][i]);
        }
    }cout<<res<<endl;
}
