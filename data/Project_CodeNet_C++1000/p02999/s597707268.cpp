#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define ul unsigned long long int
#define ld long double
#define f(t) for(ll i =0;i<t;i++)
#define vi vector<int>
#define vl vector<ll>
#define pb push_back
#define ff first
#define ss second
#define MOD 1000000007
#define inf 4e18
#define EPS 1e-3
#define PI 3.1415926535897932385
#define display(v) f(v.size())cout << v[i]<<" "
const double h = 1e-6;
const int MAX_  = 200005;
#define all(v) v.begin(),v.end()

inline ll mul(ll a, ll b){ return (a * 1ll * b) % MOD; }
inline ll sub(ll a, ll b){ ll c = a - b; if(c < 0) c += MOD; return c; }
inline ll add(ll a, ll b){ ll c = a + b; if(c > MOD) c -= MOD; return c; }
ll sqr(ll x)
{
    return x*x;
}
 //////////////////////*********CODE***********/////////////////////
 //////////////////////////////////////////////////////////////////


int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int x,a;  cin>>x>>a;
    if(x<a)cout << 0 ;
    else cout << 10;
    
   
   
    return 0;
}
    