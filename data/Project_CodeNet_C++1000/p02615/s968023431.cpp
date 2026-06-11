#include <bits/stdc++.h>
#define pii pair<int,int>
#define eb emplace_back
#define MOD 1000000007
#define int long long
using namespace std;
#define s second
#define f first

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n, mx=1e9+1;
    cin >> n;
    vector<int> v(n);
    for(int i=0;i<n;i++)
        cin >> v[i];
    sort(v.begin(),v.end(),greater<int>());
    int ans = v[0];
    int t = 2, i=1;
    bool x = false;
    while( t<n )
    {
        ans += v[i];
        i += x;
        x = !x;
        t++;
    }
    cout << ans;
}