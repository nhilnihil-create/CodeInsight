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
#define mod   998244353
#define PI 2*acos(0.0)
#define dbg(a) cout<<#a<<" ->->->-> "<<a<<"\n"
int dirx[] = {1, -1,0, 0}, diry[] = {0, 0, 1, -1};

ll bigmod(ll x, ll p)
{
    ll res = 1;
    while(p)
    {
        if(p&1)
            res = (res*x)%mod;
        x = (x*x)%mod;
        p >>= 1;
    }
    return res;
}

//=============================================ASIFAZAD==============================================//

struct scr
{
    int a, b, c, d;
};

scr ck[60];
vi sq(20);
int n,m, q, ans;

void dfs(int num, int pos)
{
    if(pos >= n)
    {
        int ac = 0;
        for(int i = 0; i < q; i++)
            if(sq[ck[i].b] - sq[ck[i].a] == ck[i].c)
                ac+= ck[i].d;
        ans =  max(ans, ac);
        return;
    }
    sq[pos] = num;
    for(int j = num; j <= m; j++)
        dfs(j, pos + 1);
}

int32_t main()
{
    io;
    cin>>n>>m>>q;
    for(int i = 0; i< q; i++)
    {
        cin>>ck[i].a >>ck[i].b>>ck[i].c >>ck[i].d;
        ck[i].a--;
        ck[i].b--;
    }
    for(int i = 1; i <= m; i++)
        dfs(i, 0);
    cout<<ans;
    return 0;
}

