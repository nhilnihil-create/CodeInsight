#include <bits/stdc++.h>
#define pii pair<int,int>
#define eb emplace_back
#define MOD 1000000007
#define int long long
using namespace std;
#define s second
#define f first

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int x, k, d;
    cin >> x >> k >> d;
    x = abs(x);
    int ans;
    if( (x / d) > k )
        ans = x - k * d;
    else
    {
        int y = x % d;
        k -= (x - y) / d;
        k %= 2;
        if(k & 1)   ans = d - y;
        else        ans = y;
    }
    cout << ans;
}