#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main()
{
    ll a,b,c,d;
    cin >> a >> b >> c >> d;
    ll ans;
    ans=max(a*c,max(a*d,max(b*c,b*d)));
    cout << ans << endl;
}
