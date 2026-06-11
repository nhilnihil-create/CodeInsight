#include <bits/stdc++.h>
using namespace std;
#define ll long long
ll n, ans[100005], a[100005], temp,f = 1;
int main()
{
    //ios::sync_with_stdio(false);
    cin >> n;
    for(int i = 1; i <= n; ++i) cin >> a[i], temp += 2 * f * a[i], f *= -1;
    ans[1] = temp / 2;
    cout << ans[1] <<' ';
    for(int i = 2; i <= n; ++i){
        ans[i] = 2 * a[i - 1] - ans[i - 1];
        cout << ans[i] << ' ';
    }

    return 0;
}