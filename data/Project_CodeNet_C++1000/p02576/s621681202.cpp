#include <bits/stdc++.h>
using namespace std;
#define IOS                           \
    std::ios::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL);
    void solve()
    {
        int n,x,t;
        cin >> n>>x >>t;
        cout << (((n+x-1)/x)*t);
    }
    int main()
    {
        IOS
        int t=1;
        while(t--)
        solve();
        return 0;
    }