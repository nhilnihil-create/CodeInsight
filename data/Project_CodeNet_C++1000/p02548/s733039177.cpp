//Rafiqul Islam, MBSTU,ICT

#include <cstdio>
#include <algorithm>
#include <vector>
#include <set>
#include <queue>
#include <algorithm>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <iostream>
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;

#define pb push_back
#define mk make_pair
#define f0(i,b) for(int i=0;i<(b);i++)
#define f1(i,b) for(int i=1;i<=(b);i++)
#define f2(i,a,b) for(int i=(a);i<=(b);i++)
#define sf(a) scanf("%d",&a);
#define sfl(a) scanf("%lld",&a);
#define pf(a) printf("%d\n",a);
#define pfl(a) printf("%lld\n",a);
#define TEST int test; cin >> test ;while(test--)
#define ii pair<int,int>
#define iil pair<ll,ll>
#define loop(i,a,b) for(int i = a ; i < b ; i++)
#define INF 2147483647
#define endl "\n"
#define all(v) v.begin(),v.end()
#define SET(a)      memset((a), -1, sizeof(a))
#define CLR(a)      memset((a), 0, sizeof(a))

int dx8[] = {0, 0, 1, 1, 1, -1, -1, -1};
int dy8[] = {1,-1, 1, -1, 0, 0, -1, 1};
int dx4[] = {0, 0, 1, -1};
int dy4[] = {1, -1, 0, 0};

const double pi = acos(-1.0);
const ll mod = 1e9 + 7;;
const ll maxn = 1e6+5;

ll power(ll x, unsigned long long y)
{
    ll res = 1;     // Initialize result

    while (y > 0)
    {
        // If y is odd, multiply x with result
        if (y & 1)
            res = (res*x)%mod;

        // y must be even now
        y = y>>1; // y = y/2
        x = (x*x)%mod;  // Change x to x^2
    }
    return res%mod;
}
ll modOp(ll a, ll b)
{
    ll c = a % b;
    if (c < 0)
        c += b;
    return c;
}
ll iv[maxn + 1];
void mod_inv()
{
    iv[1] = 1;
    for(ll i = 2 ; i <= maxn ; i++ )
    {

        iv[i] = (mod - mod/i * iv[mod%i]%mod)%mod;
        //cout << iv[i] << endl;
    }
}

ll Logn(ll n, ll base)
{
    return (n > base - 1) ? 1 + Logn(n / base, base) : 0;
}
vector<vector<int>> adj;
vector<int>sub_tree_size;
vector<array<int,2>> edge;
void dfs(int child, int parant)
{
    sub_tree_size[child] = 1;
    for(int x: adj[child])
    {
        if(x == parant)
            continue;

        dfs(x,child);
        sub_tree_size[child] += sub_tree_size[x];
    }

}
int isPrime[1000001] ;
vector< vector<ll> > pff(1000000), pr(1000000);
void sieve(int n)
{
    for(int i = 2 ; i*i <= n ; i++)
    {
        if(isPrime[i] == 0)
        {
            for(int j = i+i ; j <= n; j = j + i)
            {
                isPrime[j] = 1;
            }
        }
    }
    return;
}
int d[1000001];
void run_case()
{
    //sieve(1000000);

    for(int i = 1 ; i <= 1e6 ; i++)
      for(int j = i; j <= 1e6; j+=i)
          d[j]++;

    ll n;
    cin >> n;
    ll a[n+10];
    a[0] = 0;
    a[1] = 0;
    a[2] = 1;
    a[3] = 3;
    for(int i = 4 ; i <= n ; i++)
    {
       a[i] = a[i-1]+d[i-1];
    }
    cout << a[n] << endl;
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    //TEST
    run_case();
    //main();
    return 0;
}
