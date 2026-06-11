#include <iostream>
#include <bits/stdc++.h>
#define mod 1000000007
#define point complex<long long>
#define pi acos(-1)
#define pb push_back


typedef long long ll;

using namespace std;

void Fastio(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
}

long long adotb(point a, point b){
    return (conj(a)*b).real();
}

long long acrossb(point a, point b){
    return (conj(a)*b).imag();
}

long long sinseta(point a, point b){
    return abs(acrossb(a,b)/(abs(a)*abs(b)));
}
ll fact[1000006], inv[1000006];

ll fp(ll base, ll exp)
{
    if (exp == 0)
        return 1;
    ll ans = fp(base, exp / 2);
    ans = (ans * ans) % mod;
    if (exp % 2 != 0)
        ans = (ans * (base % mod)) % mod;
    return ans;
}

void calcFacAndInv(ll n)
{
    fact[0] = inv[0] = 1;
    for (ll i = 1; i <= n; i++)
    {
        fact[i] = (i * fact[i - 1]) % mod;
        inv[i] = fp(fact[i], mod - 2);
    }
}

ll ncr(ll n, ll r)
{
    return ((fact[n] * inv[r]) % mod * inv[n - r]) % mod;
}

ll npr(ll n, ll r)
{
    return (fact[n] * inv[n - r]) % mod;
}

ll lcm(ll a, ll b){
    return (a*b)/__gcd(a,b);
}
long double  NCR(int n, int m){
    if(n<m)return 0;
    long double res = 1;
    m = min(m, n - m);
    for(int i = 0; i < m; i++){
        res = res * ( n - i) / (i + 1);
 }
    return res;
}
ll stolong(string a){
    ll res=0;
    while(a[0]=='0'){
        a.erase(a.begin());
    }
    if(a=="")a="0";
    for(int i=0; i<a.size(); i++){
        res*=10; res+=a[i]-'0';
    }
    return res;
}
const int MAXN=1e7+2;
int spf[MAXN];
void sieve()
{
    spf[1] = 1;
    for (int i=2; i<MAXN; i++)
        spf[i] = i;

    for (int i=4; i<MAXN; i+=2)
        spf[i] = 2;

    for (int i=3; i*i<MAXN; i++)
    {
        if (spf[i] == i)
        {
            for (int j=i*i; j<MAXN; j+=i)
                if (spf[j]==j)
                    spf[j] = i;
        }
    }
}

set<int> getFactorization(int x)
{
    set<int> ret;
    while (x != 1)
    {
        ret.insert(spf[x]);
        x = x / spf[x];
    }
    return ret;
}
class data{
    public:
    ll x, y, d;
    /*bool operator <(data& d)const {
        return l<d.l || (l==d.l && r>=d.r);
    }*/

};

double distance(point a, point b){
    return abs(b-a);
}

string ltobin(int x){
    string res="";
    while(x){
        res+=('0'+(x%2)); x/=2;
    }
    reverse(res.begin(), res.end());
    return res;
}
ll bintol(string a){
    ll res=0;
    reverse(a.begin(), a.end());
    for(int i=0; i<a.size(); i++){
        if(a[i]=='1')res+=pow(2,i);
    }
    return res;
}
void primeFactors(int n)
{
    while (n % 2 == 0 && n)
    {
        cout<<2<<" ";
        n = n/2;
    }
    for (int i = 3; i <= sqrt(n); i = i + 2)
    {
        while (n % i == 0)
        {
            cout<<i<<" ";
            n = n/i;
        }
    }
    if (n > 2)
        cout<<n<<" ";
}

vector<int> Sieve(int n)
{
    int p[1000005];
    for(int i=2; i<=n; i++){
        for(int y=i+i; y<=n; y+=i){if(!p[y])p[y]=i;}
    }
    vector<int>v;
    for(int i=2; i<=n; i++){
        if(!p[i])v.push_back(i);
    }
    return v;
}

int main()
{
    Fastio();
    int ttt=1; //cin>>ttt;
    while(ttt--){
        ll n; cin>>n;
        ll arr[n+2]={0};
        for(int i=0; i<=n; i++){cin>>arr[i];}
        ll res=0;
        for(int i=0; i<n; i++){
            ll x; cin>>x;
            ll t=min(x, arr[i]); arr[i]-=t; res+=t; x-=t;
            if(x){
                t=min(x, arr[i+1]);
                arr[i+1]-=t; res+=t;
            }
        }
        cout<<res<<'\n';
    }

    return 0;
}
