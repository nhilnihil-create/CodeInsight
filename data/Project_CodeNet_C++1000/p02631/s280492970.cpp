#include <bits/stdc++.h>
using namespace std;
const long long N = 2e5+5 , M = 998244353, OO = 0x3f3f3f3f;
typedef long long ll;
#define FIO ios_base::sync_with_stdio(0);cin.tie(0);
const double Pii = 3.14159265359;
ll n;
ll a[N];
int main()
{
    FIO
    cin >> n;
    ll tot = 0;
    for(int i=0; i<n; ++i)
    {
        cin >> a[i];
        tot ^= a[i];
    }
    for(int i=0; i<n; ++i) a[i]^= tot;
    for(int i=0; i<n; ++i) cout << a[i] << " ";
    cout << endl;

    return 0;
}
