#include <bits/stdc++.h>
using namespace std;
#define pow2(x) ((x)*(x))
#define mod(x, m) ((((x) % (m)) + (m)) % (m))
#define max3(a, b, c) max(a, max(b, c))
#define min3(a, b, c) min(a, min(b, c))
#define f(i,n) for(int i=0;i<n;i++)
#define pb push_back
#define mp make_pair
#define fi first
#define sec second
#define fast ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
typedef long long ll;
typedef pair<ll, ll> ii;
typedef pair<ll, ii> iii;
typedef vector<int> vi;
typedef vector<ii> vii;
typedef vector<iii> viii;
typedef set <ll> se;
typedef queue<ll> Q;
struct hash_pair { 
    template <class T1, class T2> 
    size_t operator()(const pair<T1, T2>& p) const
    { 
        auto hash1 = hash<T1>{}(p.first); 
        auto hash2 = hash<T2>{}(p.second); 
        return hash1 ^ hash2; 
    } 
}; 
// unordered_map<ii, hash_pair> umap;
bool sort1(const pair<pair<int,int>, int> &a, 
              const pair<pair<int,int>, int> &b) 
{ 
    return (a.fi.second < b.fi.second); 
}
bool sort2(const pair<pair<int,int>, int> &a, 
              const pair<pair<int,int>, int> &b) 
{ 
    return (a.fi.first > b.fi.first); 
}
ll lcm(ll a, ll b)
{
    ll gcd = __gcd(a,b);
    ll l = (a*b)/gcd;
    return l;
}
// unordered_map<int, int> umap;
int mod =1000000007 ;


// Returns n^(-1) mod p 
// long long modInverse(ll n, ll p) 
// { 
//     return power(n, p - 2, p); 
// } 


int main()
{
    fast;
    int t=1;
    // cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        string s = "";
        string w = "ACL";
        while(n--) s+=w;
        cout<<s;
    }
}