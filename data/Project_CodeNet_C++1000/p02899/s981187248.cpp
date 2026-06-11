#include <bits/stdc++.h>
using namespace std;

#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL)
#define ll long long
#define inf 1e18
#define pi acos(-1.0)
#define mod 998244353

int main(void)
{
    fastio;

    int n,a,p[100005],i;
    cin >> n;
    for(i=1;i<=n;i++)
    {
        cin >> a;
        p[a]=i;
    }
    for(i=1;i<=n;i++)cout << p[i] << " ";
    return 0;
}
