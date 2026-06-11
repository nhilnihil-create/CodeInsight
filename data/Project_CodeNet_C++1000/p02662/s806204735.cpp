
#include <bits/stdc++.h>
#define int long long
using namespace std;

const int Mod = 998244353;
const int Sz = 3e3 + 1;

int n, k;
int a[Sz];
int f[Sz][Sz];
int dp(int pos, int w){
    if(w > k) return 0;
    if(pos > n && w == k) return 1;
    if(pos > n) return 0;
    int &res = f[pos][w];
    if(res != -1) return res;
    res = (dp(pos + 1, w) * 2 + dp(pos + 1, w + a[pos])) % Mod;
    return res;
}
int32_t main()
{
    memset(f, -1, sizeof(f));
    //freopen("inp.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> k;
    for(int i = 1; i <= n; i++) cin >> a[i];
    cout << dp(1, 0);
    return 0;
}
