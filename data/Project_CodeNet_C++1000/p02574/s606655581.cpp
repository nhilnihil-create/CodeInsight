#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
typedef unsigned long long int ull;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef vector<ull> vull;
typedef pair<int, int> pii;
typedef pair<pii, int> piii;
typedef pair<ll, ll> pll;
struct pair_hash {
    template <class T1, class T2>
    size_t operator () (const pair<T1,T2> &p) const {
        auto h1 = hash<T1>{}(p.first);
        auto h2 = hash<T2>{}(p.second);
        return h1 ^ h2;  
    }
};
using Vote = pair<ll,ll>;
using Unordered_map = unordered_map<Vote, int, pair_hash>;
#define FOR(i,a,b) for(ll i=a;i<b;i++)
#define FORD(i,a,b) for(ll i=a;i>=b;i--)
#define showvec(arr,a,b) for(ll i=a;i<b;i++) cout<<arr[i]<<" ";
#define read_input(arr,a,b) for(ll i=a;i<b;i++) cin>>arr[i];
#define pb push_back
#define mp make_pair
#define F first
#define S second
#define endl '\n'
#define SmooothOperatorrrrr()                 \
    ios_base::sync_with_stdio(0); \
    cin.tie(0);                    \
    cout.tie(0);                   
#define deci(n) cout<<fixed<<setprecision(n)
const int mod=998244353;
const int mod2=1000000007;
#define M_PI 3.14159265358979323846
#define LL_MAX 9223372036854775807
#define MAXN 2000001
/**************************************************************************************************/

bool prime[2000005];

int gcd(int a, int b) 
{ 
    if (a == 0) 
        return b; 
    return gcd(b % a, a); 
} 
  
// Function to find gcd of array of 
// numbers 
int findGCD(int arr[], int n) 
{ 
    int result = arr[0]; 
    for (int i = 1; i < n; i++) 
    { 
        result = gcd(arr[i], result); 
  
        if(result == 1) 
        { 
           return 1; 
        } 
    } 
    return result; 
}

void Sieve() 
{
    int n=2000004;
    memset(prime, true, sizeof(prime));
    prime[1]=false;
    prime[0]=false;
    for (int p=2; p*p<=n; p++) 
    { 
        if(prime[p]==true)
        {
            for (int i=p*p; i<=n; i += p) 
                prime[i] = false; 
        } 
    }
}

vi primeFactors(int n)
{
    unordered_map<int,int> primes;
    while(n%2==0)
    {
        primes[2]=1;
        n=n/2;
    }
    for(int i=3;i<=sqrt(n);i+=2)
    {
        while(n%i==0)
        {
            primes[i]=1;
            n=n/i;
        }
    }
    if(n>2)
        primes[n]=1;
    vi v;
    for(auto x=primes.begin();x!=primes.end();x++)
        v.pb(x->first);
    return v;
}

int main()
{
    SmooothOperatorrrrr();
    int n;cin>>n;
    int a[n];
    read_input(a,0,n);
    int array_gcd=findGCD(a,n);
    if(array_gcd!=1)
        cout<<"not coprime\n";
    else
    {
        Sieve();
        int ok=1;
        unordered_map<int,bool> check_prime;
        FOR(i,0,n)
        {
            vi v=primeFactors(a[i]);
            FOR(j,0,v.size())
            {
                if(check_prime[v[j]])
                {
                    ok=0;
                    break;
                }
                check_prime[v[j]]=1;
            }
        }
        if(ok)
            cout<<"pairwise coprime\n";
        else
            cout<<"setwise coprime\n";
    }
}