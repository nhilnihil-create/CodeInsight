/*BISMILLAH
THE WHITE WOLF
NO DREAM IS TOO BIG AND NO DREAMER IS TOO SMALL*/

#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef vector<long long> vll;
typedef vector<int> vi;

#define io ios_base::sync_with_stdio(false)
#define pb push_back

#define eb emplace_back
#define mod   1000000007
#define PI 2*acos(0.0)
#define all(r)(r).begin(),(r).end()
#define dbg(a) cout<<#a<<" ->->->-> "<<a<<"\n"
#define inf 1000000000000000000
#define N 20000
int dirx[] = {1, -1,0, 0}, diry[] = {0, 0, 1, -1};


//=============================================ASIFAZAD==============================================//
ll dp[10005][1005];
int h, n;
vi a, b;

ll rec(int ht, int pos)
{
    if(ht <= 0)
        return 0;
    if(pos >= n)
        return INT_MAX;
    if(dp[ht][pos] != -1)
        return dp[ht][pos];
    ll c = 0, d = 0, f = 0;
    c = rec(ht, pos + 1);
    d = rec(ht-a[pos], pos + 1) + b[pos];
    f = rec(ht-a[pos], pos) + b[pos];
    return dp[ht][pos] = min(c, min(d, f));
}

int32_t main()
{
    io;
    cin>>h>>n;
    for(int i = 0;i < n; i++)
    {
        int x, y;
        cin>>x>>y;
        a.push_back(x);
        b.push_back(y);
    }
    memset(dp, -1, sizeof(dp));
    cout<<rec(h, 0);
    return 0;
}
