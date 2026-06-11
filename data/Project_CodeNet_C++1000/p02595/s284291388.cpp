#include <bits/stdc++.h>

using namespace std;

#define lli long long int
#define x first
#define y second

lli x, y, n, d, ans;

int main()
{
 //   freopen("Bao.inp","r",stdin);
    cin >> n >> d;
    for(int i = 1; i <= n; ++i)
    {
        cin >> x >> y;
        if(sqrt(pow(x,2) + pow(y,2)) <= d)
        {
            ans++;
        }
    }
    cout << ans;
    return 0;
}
