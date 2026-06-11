#include <bits/stdc++.h>
#define int long long 
using namespace std;
const int maxn = 2e5 + 7;
int n, k, sum[maxn], val[maxn], ans;
map<int, int> mp;

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    if(fopen("test.inp", "r")) freopen("test.inp", "r", stdin);
    cin >> n >> k;
    mp[0] = 1;
    for(int i = 1; i <= n; i++)
    {
        int x;
        cin >> x;
        sum[i] = (sum[i - 1] + x) % k;
        val[i] = ((sum[i] - i) % k + k) % k;
        if(i - k >= 0)
        {
            mp[val[i - k]]--;
        }
        ans += mp[val[i]];
        mp[val[i]]++;
    }
    cout << ans;
}