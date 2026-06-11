#include <bits/stdc++.h>
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<ll, ll>pll;
int main()
{
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    ll n, c = 0;
    cin >> n;
    ll arr[n + 5];
    for(int i = 1;i <= n;++i)
    {
        ll x;
        cin >> x;
        c += (x != i);
    }
    cout << (c <= 2 ? "YES" : "NO");
    return 0;
}
