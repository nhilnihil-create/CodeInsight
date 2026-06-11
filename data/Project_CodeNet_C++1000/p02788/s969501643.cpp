/*BISMILLAH
THE WHITE WOLF
NO DREAM IS TOO BIG AND NO DREAMER IS TOO SMALL*/

#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
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

int32_t main()
{
    io;
    int n, d, a;
    cin>>n>>d>>a;
    ll ans = 0;
    vector<pll> inp(n);
    for(int i = 0; i< n;i++)
    {
        ll x, y;
        cin>>x>>y;
        y = (y + a -1)/a;
        inp[i].first = x;
        inp[i].second = y;
    }
    ll cur = 0;
    sort(all(inp));
    map<ll, ll> mark;
    for(int i =0 ; i< n;i++)
    {
        cur -= mark[i];
        inp[i].second -= cur;
        if(inp[i].second <= 0)
            continue;
        ans += inp[i].second;
        cur += inp[i].second;
        int l = i, h = n-1, pos = -1, mid;
        while(l <= h)
        {
            mid = (l + h)/2;
            if(inp[mid].first > inp[i].first + 2*d)
            {
                pos = mid;
                h = mid - 1;
            }
            else
                l = mid + 1;
        }
//        dbg(cur);
//        dbg(pos);
        if(pos != -1)
            mark[pos] += inp[i].second;
    }
    cout<<ans;
    return 0;
}