#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
ll mod=1e9+7;
#define endl '\n'
#define SIGMA 128
const ld PI=3.14159265358979;
#define fr(i,n) for(i=1;i<=n;i++)
#define rep(i,k,n) for(i=k;i<=n;i++)
#define w(x) int x;cin>>x;while(x--)
#define pb push_back
#define eb emplace_back
#define mp make_pair
#define deb(x) cout << #x << "=" << x << endl
#define deb2(x, y) cout << #x << "=" << x << "," << #y << "=" << y << endl
#define ps(x,y) cout<<fixed<<setprecision(y)<<x<<endl
#define pb push_back
#define all(x) x.begin(),x.end()
#define vi vector<int>
#define vll vector<ll>
#define vvl vector<vll>
#define ppi pair<int,int>
#define ppl pair<ll,ll>
#define F first
#define S second 
#define LB lower_bound
#define UB upper_bound
#define mset multiset
#define uset unordered_set
#define umap unordered_map
#define IOS ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
ll binpow(ll x, ll y, ll p){  ll res = 1;x = x % p;if (x == 0)return 0;while (y > 0)  { if (y & 1) res = (res*x) % p; y = y>>1;x = (x*x) % p;}return res;}  
ll gcd(ll a, ll b){ if (b == 0) return a; return gcd(b, a % b); } 
bool parity(ll x,ll y){ bool f = ((x ^ y) < 0);return !f;}


int main()
{
    // #ifndef ONLINE_JUDGE
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    // #endif

    IOS

    ll n,a,b;
    cin>>n>>a>>b;
    
    if((b-a)%2==0)
    {
        cout<<(b-a)/2<<endl;
    }
    else
    {
        ll ans;
        ll newa=1;
        ll newb=b-a+1;
        if((newb-newa)%2==0)
        {
            ans=(a-1+(newb-newa)/2);
        }
        else
        {
            ans=(a-1+(newb-newa)/2+1);
        }

        newa=a+n-b;
        newb=n;
        if((newb-newa)%2==0)
        {
            ans=min(ans,(n-b+(newb-newa)/2));
        }
        else
        {
            ans=min(ans,(n-b+(newb-newa)/2+1));
        }
        cout<<ans<<endl;
    }
    

    return 0;  
}

