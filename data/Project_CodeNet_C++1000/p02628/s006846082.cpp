#include <bits/stdc++.h>
#define MEM 100006
#define sanic ios_base::sync_with_stdio(0)
#define pb push_back
using namespace std;
typedef long long ll;
typedef pair<ll, ll> pii;
const ll MOD = 1e9+7;
ll n,m,ans;
ll a[MEM];
int main()
{
    sanic; cin.tie(0);
    cin >> n >> m;
    for(int i=0; i<n; i++)
        cin >> a[i];
    sort(a,a+n);
    for(int i=0; i<m; i++)
        ans += a[i];
    cout << ans;
}
