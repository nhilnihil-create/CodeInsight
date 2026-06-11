#include<bits/stdc++.h>
typedef long long int ll;
using namespace std;

void solve()
{
    int n;
    cin >> n;

    ll s = 1;
    ll a[n];
    for(int i = 0; i<n; i++)
    {
        cin >> a[i];
        if(a[i]==0)
        {
            cout << 0 << endl;
            return ;
        }
    }
    for(int i = 0; i<n; i++)
    {
        if(s>(ll)1e18/a[i])
        {
            cout << -1 << endl;
            return ;
        }
        s *= a[i];
    }
    cout << s << endl;
}


int main()
{
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll t;
    solve();
    return 0;
}
