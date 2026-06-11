#include <bits/stdc++.h>
using namespace std;
const long long N = 2e5+5 , M = 1e9+7, OO = 0x3f3f3f3f;
typedef long long ll;
#define FIO ios_base::sync_with_stdio(0);cin.tie(0);
const double Pii = 3.14159265359;
ll n;
ll a[N], d[N], fr[N];

int main()
{
    FIO
    cin >> n;
    for(int i=0; i<n; ++i)
    {
        cin >> a[i];
        d[i] = i-a[i];
    }
    for(int i=0; i<n; ++i)
        if(d[i] < N && d[i] >= 0) fr[d[i]]++;
    ll ans =0;
    for(int i=0; i<n; ++i)
    {
        int didx = a[i]+i;
        if(didx >= 0 && didx < N) ans += fr[didx];
        //cout << didx << " " << fr[didx] << endl;
    }
    cout << ans << endl;
    return 0;
}


