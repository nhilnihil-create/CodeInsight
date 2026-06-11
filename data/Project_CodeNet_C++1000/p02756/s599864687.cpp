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
#define mod   1000000000
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


int32_t main()
{
    io;
    string s;
    cin>>s;
    deque<char> inp;
    for(auto x: s) inp.pb(x);

    bool cur = 0;
    int q;
    cin>>q;
    while(q--)
    {
        int ck;
        cin>>ck;
        if(ck == 1)
            cur ^= 1;
        else
        {
            int f;
            char c;
            cin>>f>>c;
            if(cur)
                f = (f == 1? 2:1);
            if(f == 1)
                inp.push_front(c);
            else
                inp.push_back(c);
        }
    }
    if(cur)
        reverse(inp.begin(), inp.end());
    for(auto x: inp) cout<<x;
    return 0;
}
