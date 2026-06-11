                    /*In the name of ALLAH, Most Gracious, Most Merciful*/
#include<bits/stdc++.h>

#define ll                      long long int
#define ull                     unsigned long long int
#define PI                      2*acos(0.0)
#define sqr(x)                  (x)*(x)
#define EPS                     10E-10
#define MOD                     1000000007
#define longlimit               92233720368547758
#define infinity                (1<<28)
#define setbits                 __builtin_popcount
#define zerobits                __builtin_ctzll
#define parity(n)               __builtin_parity(n)
#define pb(a)                   emplace_back(a)
#define mp                      make_pair
#define ff                      first
#define ss                      second
#define gcd(a, b)               __gcd(a,b)
#define lcm(a, b)               ((a)*(b))/gcd(a,b)
#define watch(x)                cout << (#x) << " is " << (x) << endl
#define TEST_CASES()            ll t;cin>>t;while (t--)
#define PRECISION(a,x)          fixed<<setprecision(x)<<a<<endl;
#define endl                    "\n"
#define all(a)                  (a.begin()),(a.end())
#define UNIQUE(X)               (X).erase(unique(all(X)),(X).end())
#define DELETE(X)               (X).erase (remove (all(X)),(X).end())
#define SORT_UNIQUE(c)          (sort(c.begin(),c.end()), c.resize(distance(c.begin(),unique(c.begin(),c.end()))))
#define FAST_IO()               ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define FILE_IO()               freopen("output.txt", "w", stdout);freopen("input.txt", "r", stdin)
using namespace std;

ll MAX_PRIME_DIV(ll n)
{
    ll maxi=INT_MIN;
    for (ll i=2;i*i<=n;i++)
    {
        if (n%i==0)maxi=max(maxi,i);
    }
    if (maxi==INT_MIN)return INT_MIN;
    return maxi;
}
void solve()
{
   string s;
   cin>>s;
   vector<string>v={"0","SUN", "MON", "TUE", "WED", "THU", "FRI","SAT"};
   for (int i=1;i<v.size();i++)
   {
       if (s==v[i])
       {
           cout<<(7-i+1)<<endl;
       }
   }
}

int32_t main()
{
    FAST_IO();
    //TEST_CASES()
        solve();
}


