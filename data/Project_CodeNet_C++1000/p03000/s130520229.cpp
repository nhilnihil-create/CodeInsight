// Author := Abhishek Giri

#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
#define mp make_pair
#define mod 1000000007
#define V(type) vector<(type)>
#define all(c) ((c).begin(),(c).end())
#define in(var) cin>>(var)
#define out(var) cout<<(var)
#define on(var) cout<<var<<"\n"
#define f(i,n) for(ll i = 0 ; i < n ;i++)
#define mfor(i,init,n,b) for(ll i = (init) ; i < (n) ; i+= (b))
#define cfor(i,c) for(auto i = (c).begin() ; i!= (c).end(); i++)
#define el "\n"

/*##################################################################################*/


int prime[1000000] ;
vector < int > pr;
void calculateprime()
{
    prime[0] = prime[1] = 1 ;
    for(int i = 2 ; i <= 1000000 ; i++)
    {
        if(prime[i] == 0)
        {
            pr.pb(i);
            for(ll j = i*2 ; j <= 1000000 ; j += i )
            {
                prime[j] = 1 ;
            }
        }
    }
}


void fast(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}

bool isprime(ll n)
{
    for(ll i = 2 ; (ll) i*i <= n ; i++)
    {
        if(n % i == 0){
            return false;
        }
    }
    return true;
}

ll fib(int n)
{
  ll a = 0, b = 1, c, i;
  if( n == 0)
    return a;
  for (i = 2; i <= n; i++)
  {
    c = (a + b);
    a = b;
    b = c;
  }
  return b;
}


ll gcd(ll a, ll b)
{
    if (b == 0)
        return a;
    return gcd(b, a % b);
}

ll extendedgcd(ll a, ll b, ll& x, ll& y) {
    if (b == 0) {
        x = 1;
        y = 0;
        return a;
    }
    ll x1, y1;
    ll d = extendedgcd(b, a % b, x1, y1);
    x = y1;
    y = x1 - y1 * (a / b);
    return d;
}

ll findgrouplcm(vector<int> &arr, int n)
{
    ll ans = arr[0];

    for (ll i = 1; i < n; i++)
        ans = (arr[i] * (ans/(gcd(arr[i], ans))));

    return ans;
}


ll powerwithmod(ll x, unsigned ll y, ll p)
{
    ll res = 1;

    x = x % p;

    if (x == 0) return 0;

    while (y > 0)
    {
        if (y & 1)
            res = (res*x) % p;

        y = y>>1; // y = y/2
        x = (x*x) % p;
    }
    return res;
}


bool comp(const pair<int,int> &a , const pair<int,int> &b){
    return a.first < b.first;
    if(a.first == b.first)  return a.second < b.second;
}


void solve(){
    int n,x;
    in(n)>>x;
    int arr[n];
    f(i,n){
        in(arr[i]);
    }
    int cur = 0 , cnt = 1;
    f(i,n){
        cur += arr[i];
        if(cur > x)    break;
        ++cnt;
    }
    out(cnt);
}


int main() {
    fast();
    ll t = 1;
    //cin>>t;
    while(t--)
    {
        solve();
    }

    return 0;
}
