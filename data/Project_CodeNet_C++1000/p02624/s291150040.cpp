#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 1e7 + 5;
ll f[N], n, ans;
int main()
{
    ios::sync_with_stdio(false);
    for (int i = 1; i < N; i++)
        for (int j = i; j < N; j += i)
            f[j]++;
    cin >> n;
    for (int i = 1; i <= n; i++)
        ans += f[i] * i;
    cout << ans << endl;
    return 0;
}