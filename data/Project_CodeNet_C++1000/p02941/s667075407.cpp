// #pragma GCC target ("avx2")
// #pragma GCC optimization ("O3")
// #pragma GCC optimization ("unroll-loops")
#include <bits/stdc++.h>
using namespace std;
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define mod 998244353
#define int long long
#define inf 200000000000
const int maxnodes=1005;
#define ll long long
#define N 2501
#define EPS 0.01
#define ld long double



int32_t main()
{
    IOS;
    int n;
    cin >> n;
    vector<int> a(n),b(n);
    set<pair<int,int>> s;

    for(int i = 0;i < n;i++)
        cin >> a[i];
    for(int i = 0;i < n;i++)
    {
        cin >> b[i];
        s.insert({b[i],i});
    }
    int ans = 0;
    int cnt = 20;
    while(!s.empty())
    {
        int i = s.rbegin()->second;
        s.erase(--s.end());
        int sub = b[(i+1+n)%n] + b[(i-1+n)%n];
        if((b[i] - a[i]) % sub == 0)
        {
            ans += (b[i] - a[i]) / sub;
            b[i] = a[i];
            continue;
        }
        else
        {
            ans += b[i] / sub;
            b[i] %= sub;
            if(b[i] < a[i])
            {
                cout << -1;
                return 0;
            }
            if(b[i] > max(b[(i+1+n)%n],b[(i-1+n)%n]))
            {
                cout << -1;
                return 0;
            }
            s.insert({b[i],i});
        }
    }
    cout << ans << endl;

}