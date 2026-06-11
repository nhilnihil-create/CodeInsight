#include <bits/stdc++.h>
using namespace std;
const long long N = 3e3+5 , M = 998244353, OO = 0x3f3f3f3f;
typedef long long ll;
#define FIO ios_base::sync_with_stdio(0);cin.tie(0);
const double Pii = 3.14159265359;
ll n, m;
ll mem[N][N];
ll a[N];
ll solve(int idx, int su)
{
    if(idx == n)
    {
        if(su == m) return 1;
        return 0;
    }
    if(mem[idx][su]!=-1) return mem[idx][su];
    ll op1 = 0, op2 = 0;
    if(su + a[idx] <= m) op1 = solve(idx+1, su+a[idx]);
    op2 = (solve(idx+1, su)*2);
    return mem[idx][su] = (op1 + (op2%M))%M;
}

int main()
{
    FIO
    cin >> n >> m;
    for(int i=0; i<n; ++i) cin >> a[i];
    memset(mem, -1, sizeof mem);
    ll ans = solve(0, 0);
    cout << ans << endl;
    return 0;
}

