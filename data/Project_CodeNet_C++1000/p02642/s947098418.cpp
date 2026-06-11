#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long
 
const int N = 1e6 + 5;
 
int n;
int a[N];
int have[N], mark[N];
 
void work()
{
    for(int i = 1; i < N; i++)
    {
        if(have[i])
        {
            if(have[i] >= 2)
                mark[i] = 1;
            for(int j = 2; i * j < N; j++)
                mark[i * j] = 1;
        }
    }
}
 
int32_t main()
{
    IOS;
    cin >> n;
    for(int i = 1; i <= n; i++)
    {
        cin >> a[i];
        have[a[i]]++;
    }
    int ans = 0;
    work();
    for(int i = 1; i <= n; i++)
        ans += !mark[a[i]];
    cout << ans;
    return 0;
}