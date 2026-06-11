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
#define N 2000
int dirx[] = {1, -1,0, 0}, diry[] = {0, 0, 1, -1};



//=============================================ASIFAZAD==============================================//

vi prime;
bitset<N> ck;
map<int, int> p_fact;

void seive()
{
    for(int i = 3; 1LL*i*i <= N; i+=2)
        if(ck[i] == 0)
            for(int j = i*i; j<= N; j+= 2*i)
                ck[j] = 1;
    prime.pb(2);
    for(int i = 3; i<= N; i+=2)
        if(!ck[i])
            prime.pb(i);
}

void prime_fact(int x)
{
    for(auto p: prime)
    {
        if(p*p>x)
            break;
        if(x%p == 0)
        {
            int pow = 0;
            while(x%p==0)
            {
                x/= p;
                pow++;
            }
            p_fact[p] = max(p_fact[p] , pow);
        }
    }
    if(x > 1)
        p_fact[x] = max(p_fact[x] , 1);
}

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


int32_t main()
{
    io;
    int n;
    cin>>n;
    int ans = 0, lst;
    for(int i = 0; i< n; i++)
    {
        int x;
        cin>>x;
        if(!i)
        {
            lst = x;
            ans++;
        }
        else if(lst > x)
        {
            lst = x;
            ans++;
        }
    }
    cout<<ans;
    return 0;
}
