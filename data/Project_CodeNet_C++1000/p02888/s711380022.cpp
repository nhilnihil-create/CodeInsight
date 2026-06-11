#include <bits/stdc++.h>
using namespace std;
const int maxn = 2e3 + 10;
int n, a[maxn], ans;
int main()
{
    cin >> n;
    for(int i = 1; i <= n; ++i) cin >> a[i];
    sort(a + 1, a + n + 1);
    for(int i = 1; i <= n - 2; i++)
        for(int j = i + 1; j <= n - 1; j++)
            for(int k = j + 1; k <= n; ++k){
                if(a[i] + a[j] > a[k]) ++ans;
                else break;
            }
    cout << ans << '\n';
    return 0;
}