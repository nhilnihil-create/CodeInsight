#include <bits/stdc++.h>
using namespace std;
#define Hello ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define endl '\n'
#define ll long long
int main()
{
    Hello
    int n;
    cin >> n;
    int a[n + 5], b[n + 5];
    ll ans = 0;
    for(int i = 0; i <= n; i++) cin >> a[i];
    for(int i = 0; i <  n; i++) cin >> b[i];
    for(int i = 0; i <  n; i++){
        ans += (min(a[i], b[i]));
        b[i] -= min(a[i], b[i]);
        ans += (min(a[i + 1], b[i]));
        a[i + 1] -= min(a[i + 1], b[i]);
    }
    cout << ans;
    return 0;
}
