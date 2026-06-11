#include <bits/stdc++.h>
using namespace std;
const long long N = 2e5+5 , M = 998244353, OO = 0x3f3f3f3f;
typedef long long ll;
#define FIO ios_base::sync_with_stdio(0);cin.tie(0);
const double Pii = 3.14159265359;
ll n;
ll a[N], b[N];

int main()
{
    FIO
    cin >> n;
    for(int i=0; i<n; ++i) cin >> a[i] >> b[i];
    sort(a, a+n);
    sort(b, b+n);
    if(n%2 == 1) cout << b[n/2]-a[n/2]+1 << endl;
    else cout << b[n/2-1]+b[n/2]-a[n/2-1]-a[n/2]+1 << endl;
    return 0;
}
