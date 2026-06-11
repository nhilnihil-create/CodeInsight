#include <bits/stdc++.h>

using namespace std;
#define  ll long long
#define ld long double
#define f first
#define s second
ll mod , n , a[100005];
string s;

ll solve()
{
    ll tn=1 , cur=0 , ans=0;
    for(int i=n; i>0; i--)
    {
        cur = tn*(s[i]-'0') + cur;
        cur %= mod;
        tn *= 10;
        tn %= mod;
        ans += a[cur];
        if (cur==0) ans++;

        a[cur]++;
    }
    return ans;
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    cin >> n >> mod >> s;
    s = ' '+s;

    if (mod != 2 && mod != 5)
    {
        ll ans = solve();
        cout << ans << '\n';
    }
    else
    {
        ll ans = 0;
        for(ll i=1; i<=n; i++)
        {
            int x = s[i]-'0';
            if (x%mod==0) ans += i;
        }
        cout << ans << '\n';
    }

    return 0;
}