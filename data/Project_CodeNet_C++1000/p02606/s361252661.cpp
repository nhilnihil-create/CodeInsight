#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
using namespace std;
#define rep(i, n) for(int i = 0; i < (n); ++i)
#define repA(i, a, n) for(int  i = a; i <= (n); ++i)
#define all(x) x.begin(), x.end()
#define sz(x) (int) (x).size()
#define f(a) memset(a, -1, sizeof(a))
#define fst first
#define snd second
#define mp make_pair
#define pb push_back
#define endl '\n'
#define c(m) cout<<"-1"<<endl
#define YY  cout<<"YES"<<endl
#define NY  cout<<"NO"<<endl
#define i(n) int n;cin>>n;int a[n];rep(i,n)cin>>a[i];
const int MOD=1000000007;
const int N=1000005;
typedef long long ll;
ll add(ll x, ll y)
{
    x += y;
    while(x >= MOD) x -= MOD;
    while(x < 0) x += MOD;
    return x;
}

ll mul(ll x, ll y)
{
    return (x * 1ll * y) % MOD;
}

ll binpow(ll x, ll y)
{
    ll z = 1;
    while(y)
    {
        if(y & 1) z = mul(z, x);
        x = mul(x, x);
        y >>= 1;
    }
    return z;
}

ll inv(ll x)
{
    return binpow(x, MOD - 2);
}

ll divide(ll x, ll y)
{
    return mul(x, inv(y));
}

ll fact[N];

void precalc()//factorial
{
    fact[0] = 1;
    for(int i = 1; i < N; i++)
        fact[i] = mul(fact[i - 1], i);
}

ll C(ll n, ll k)//nCr
{
    return divide(fact[n], mul(fact[k], fact[n - k]));
}

int main()
{ ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int tc;
    tc=1;
    while(tc--)
    {
      int l,r,d;
      cin>>l>>r>>d;
      int k=0;
      for(int i=1;i<=200;i++)
      {
      	if(d*i>=l&&d*i<=r)
      	k++;
      else	if(d*i>r)
      	break;
	  }
	  cout<<k;
    }
    
	return 0;
}
