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
    int a,b,c,d;
    cin>>a>>b>>c>>d;
    int flag=0;
    while(a>0 && c>0)
    {
        if(flag==0)
        {
            c-=b;
        }
        else
        {
            a-=d;
        }
        flag=1-flag;
    }
    if(a>0)
        cout<<"Yes";
    else
    {
            cout<<"No";
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