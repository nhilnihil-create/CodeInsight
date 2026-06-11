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
    int n;
    cin>>n;
    set<string> s;
    for(int i=0;i<n;i++)
    {
        string s1;
        cin>>s1;
        s.insert(s1);
    }
    cout<<s.size();
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