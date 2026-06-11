#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)


int main()
{
    int n, ans = 0;
    cin >> n;
    int l[n];

    rep(i, n) cin >> l[i];

    sort(l, l+n);

    rep(i, n)
    {
        rep(j, i)
        {
            rep(k, j)
            {
                if(l[i]!= l[j] &&
                   l[j]!= l[k] &&
                   l[i] < l[j] + l[k]
                )
                    ans++;
            }
        }
    }

    cout << ans << endl;
}