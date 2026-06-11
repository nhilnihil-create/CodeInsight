#include <bits/stdc++.h>

#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#pragma GCC optimize ("unroll-loops")
#pragma GCC optimize("Ofast")
#pragma GCC optimize ("O3")
#pragma GCC target ("avx")

typedef long long ll;
typedef long double ld;

#define fio ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define endl "\n"
#define mpq priority_queue<int,vector<int>,greater<int>>
#define debug(a) cerr << #a << ": " << a << endl
#define umii unordered_map<int64_t,int64_t>
#define ftt int t;cin>>t;for(int tt=1;tt<=t;++tt)
#define forr(i,n) for((i)=1;(i)<=(n);(i)++)
#define Rev(v) reverse(v.begin(),v.end());
#define Sort(v) sort(v.begin(),v.end());
#define Sum(v) accumulate(v.begin(),v.end(),0)
#define Input(v) for(int &x:v)cin>>x;
#define mem(a,b) memset(a,b,sizeof(a))
#define deb(x) cout<<"\nhi"<<x<<"\n"
#define pq priority_queue<int>
#define dbg cout<<"\nhi\n"
#define sayy cout<<"YES\n"
#define sayn cout<<"NO\n"
#define int long long
#define double long double
#define pii pair<int,int>
#define mii map<int,int>
#define vb vector<bool>
#define vi vector<int>
#define vii vector<pair<int,int> >
#define eb emplace_back
#define pb push_back
#define pf push_front
#define popb pop_back
#define popf pop_front
#define mp make_pair

const int MOD = 1000000007;
const double PI = 3.1415926535898;
const int LIM = 100005;

using namespace std;

int fpow( int x,int y) {
    int temp;
    if(y == 0)
        return 1;
    temp = fpow(x, y/2);
    if (y%2 == 0)
        return temp*temp;
    else
        return x*temp*temp;}

int gcd(int a,int b) {
    if(b==0)return a;
    return gcd(b,a%b);}

void sieve(int n) {
     bool prime[5*LIM];
     memset(prime, true, sizeof(prime));
     for (int p=2; p*p<=n; p++)
          if (prime[p] == true)
               for (int i=p*p; i<=n; i += p)
                    prime[i] = false;
     prime[1]=0;}

inline int read(){
    int p=1,ans=0;
    char ch=getchar();
    while(ch<48||ch>57)
    {
        if(ch=='-')p=-1;
        ch=getchar();
    }
    while(ch>=48&&ch<=57)
    {
        ans=(ans<<3)+(ans<<1)+ch-48;
        ch=getchar();
    }
    return ans*p;
}

bool isPrime(int n)
{
    // Corner cases
    if (n <= 1)
        return false;
    if (n <= 3)
        return true;

    // This is checked so that we can skip
    // middle five numbers in below loop
    if (n % 2 == 0 || n % 3 == 0)
        return false;

    for (int i = 5; i * i <= n; i = i + 6)
        if (n % i == 0 || n % (i + 2) == 0)
            return false;

    return true;
}

map<int,int> primeFactors(int n)
{
    map<int, int> mp;
    while (n % 2 == 0)
    {
        if(mp.count(2) == 1)
            mp[2]++;
        else
            mp.insert({2,1});
        n = n/2;
    }
    for (int i = 3; i <= sqrt(n); i = i + 2)
    {
        while (n % i == 0)
        {
            if(mp.count(i) == 1)
                mp[i]++;
            else
                mp.insert({i,1});
            n = n/i;
        }
    }
    if (n > 2)
    {
        if(mp.count(n) == 1)
            mp[n]++;
        else
            mp.insert({n,1});
    }
    return mp;
}

//*************************************************************************************************************************


int32_t main()
{    fio;

    int k, n, ans = -1;
    cin>>k>>n;
    vi a(n);
    Input(a);
    Sort(a);
    for(int i=1;i<n;i++)
    {
        ans = max(ans, a[i]-a[i-1]);
    }
    ans = max(ans, k-(a[n-1]-a[0]));
    cout<<k-ans;
    return 0;
}
