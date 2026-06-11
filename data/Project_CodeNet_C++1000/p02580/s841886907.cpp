#include <iostream>
#include <stdio.h>
#include <math.h>
#include <algorithm>
using namespace std;
const int maxn = 3e5 + 5;

int  x[maxn], y[maxn],cntx[maxn],cnty[maxn];

int main()
{
    int n, m, k;
    cin >> n >> m >> k;
    int mx = 0, my = 0;
    for (int i = 1; i <= k; ++i)
    {
        cin >> x[i] >> y[i];

        cntx[x[i]]++;
        mx = max(mx, cntx[x[i]]);

        cnty[y[i]]++;
        my = max(my, cnty[y[i]]);
    }
    long long  t1 = 0, t2 = 0, t = 0;
    for (int i = 1; i <= n; ++i)
        if (cntx[i] == mx)
            t1++;
    for (int i = 1; i <= m; ++i)
        if (cnty[i] == my)
            t2++;
    
    for (int i = 1; i <= k; ++i)
    {
        if (cntx[x[i]] == mx && cnty[y[i]] == my)
            t++;
    }
    if (t == t1*t2)
        cout << mx + my -1<< endl;
    else
        cout << mx + my  << endl;
    return 0;
}
