#include <bits/stdc++.h>
using namespace std;
#define int long long
#define _READ freopen("input.txt", "r", stdin);
#define _FAST                         \
    ios_base::sync_with_stdio(false); \
    cin.tie(0);                       \
    cout.tie(0);
void solve()
{
    int s,w;
    cin>>s>>w;
    if(w>=s)
        cout<<"unsafe";
    else
    {
        cout<<"safe";
    }
    
}
int32_t main()
{
    _FAST

    int t;
    t=1;
    while (t--)
    {
        solve();
        //lb:;
    }

    return 0;
}