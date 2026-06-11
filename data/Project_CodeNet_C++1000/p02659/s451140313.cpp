#include<bits/stdc++.h>
typedef long long int ll;
using namespace std;

void solve()
{
    ll a, b, d; char c;

    cin >> a >> b >> c >> d;

    b = b*100 + d;

    cout << (ll) a*b/100 << endl;
}


int main()
{
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll t;
    solve();
    return 0;
}
