#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int MOD = 1e9+7;
int main()
{
    int n;
    cin >> n;
    vector<int> a(n);
    for(int i = 0; i < n; i++) cin >> a[i];
    if(a[0] != 0)
    {
        cout << 0 << endl;
        return 0;
    }
    vector<int> v(n, 0);
    ll ans = 1;
    int count = 3;
    for(int i = 0; i < n; i++)
    {
        if(a[i] == 0)
        {
            ans = ans * count % MOD;
            count--;
            v[0]++;
            continue;
        }
        ans = ans * v[a[i]-1] % MOD;
        v[a[i]]++;
        v[a[i]-1]--;
    }
    cout << ans << endl;
}
