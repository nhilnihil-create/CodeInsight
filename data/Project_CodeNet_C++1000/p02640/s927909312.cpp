#include<bits/stdc++.h>
typedef long long int ll;
using namespace std;

void solve()
{
    int x, y;
    cin >> x >> y;

    if(y<=x*4 && y>=x*2 && y%2==0)
    {
        cout << "Yes" << endl;
    }
    else
        cout << "No" << endl;
}


int main()
{
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll t;
    solve();
    return 0;
}
