#include <bits/stdc++.h>
using namespace std;

#define rep(i, n) for (int i = 0; i < (int)(n); i++)
const int mod = 1e9+7;

int main()
{
    int x, n;
    cin >> x >> n;

    if(n == 0)
    {
        cout << x << endl;
        return 0;
    }

    int p[n];
    rep(i, n) cin >> p[i];
    sort(p, p+n);
    auto it1 = lower_bound(p, p+n, x);

    int tmp=*it1, tmpl=*it1, tmpr=*it1;

    while(tmp >= 1 && tmp <= 100)
    {
        if(!binary_search(p, p+n, tmp)) break;

        if(abs(x-tmpl) >= abs(tmpr-x))
        {
            tmpr--;
            tmp = tmpr;
        }
        else
        {
            tmpl++;
            tmp = tmpl;
        }
    }

    cout << tmp << endl;
}