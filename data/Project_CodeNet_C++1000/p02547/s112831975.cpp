#include<bits/stdc++.h>

#define ntest 0

using namespace std;
int n;
int d[105][2];
void solve()
{
    cin >> n;
    for (int i = 1; i <= n; ++i) cin >> d[i][0] >> d[i][1];
    for (int i = 1; i <= n - 2; ++i)
    {
        int ok = 1;
        for (int j = i; j <= i + 2; ++j)
        {
            if (d[j][0] != d[j][1]) ok = 0;
        }
        if (ok)
        {
            cout << "Yes\n";
            return;
        }
    }

    cout << "No\n";
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    if(ntest)
    {
        int t;
        cin >> t;
        while(t--) solve();
    }
    else
    {
        solve();
    }

}


