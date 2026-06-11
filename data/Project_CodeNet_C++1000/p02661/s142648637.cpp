#include <bits/stdc++.h>
#define int long long
#define fi first
#define se second

using namespace std;
const int MOD=1000000007;
int n;
vector <int> a,b;

int32_t main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n;
    a.resize(n);
    b.resize(n);
    for (int i=0;i<n;++i)
        cin >> a[i] >> b[i];

    sort(a.begin(),a.end());
    sort(b.begin(),b.end());

    if (n&1)
    {
        int meda,medb;
        meda = a[n/2];
        medb = b[n/2];
        cout << medb-meda+1;
    }
    else
    {
        int meda,medb;
        meda = (a[n/2 - 1] + a[n/2]);
        medb = (b[n/2 - 1] + b[n/2]);
        cout << (medb-meda) + 1;
    }
    return 0;
}
