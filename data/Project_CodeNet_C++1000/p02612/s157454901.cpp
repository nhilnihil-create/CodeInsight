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
    int n;
    cin >> n;
    int k;
    if( n%1000 == 0 )
        k = n/1000;
    else 
        k = n/1000 + 1;
    int ans = k*1000 - n;
    cout << ans ;
}   