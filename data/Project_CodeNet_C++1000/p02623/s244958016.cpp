#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    long long n, m, k; cin >> n >> m >> k;
    long long a[n+1], b[m+1], mx = 0;
    a[0] = b[0] = 0;
    for (int i = 1; i <= n; i++) { cin >> a[i]; a[i] += a[i-1]; }
    for (int i = 1; i <= m; i++) { cin >> b[i]; b[i] += b[i-1]; }
    long long i = 0;
    for (int j = n; j >= 0; j--) 
    {
        long long x = k - a[j];
        if(x < 0) continue;
        for(; i <= m; i++)
        {
            if(b[i] > x)
            {
                i--;
                break;
            }
        }
        if(i > m) i--;
        mx = max(mx, j + i);
    }
    cout << mx << '\n';
    return 0;
}
