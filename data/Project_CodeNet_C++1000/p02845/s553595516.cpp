#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const ll MOD = 1e9 + 7;

int main()
{
    int n;
    cin >> n;

    vector<ll> list(n);
    vector<ll> cnt(100010, 0);
    cnt[0] = 3;
    ll ans = 1;
    for(int i = 0; i < n; i++)
    {
        cin >> list[i];
        ans = (ans * cnt[list[i]]) % MOD;
        cnt[list[i]]--;
        cnt[list[i] + 1]++;
    }
    cout << ans << endl;
    return 0;
}