#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
#include<set>
#include<map>
using namespace std;
#define ll long long
#define pb push_back
#define rep(i,n) for(int i=0; i<n; i++)
#define forp(i,a,b) for(int i=a;i<b;i++)
#define forn(i,a,b) for(int i=a;i>=b;i--)
#define All(x,v) for(auto x:v)
#define arrin(a,n) ll a[n]; rep(i,n) cin>>a[i]
#define vi vector<int>
#define nl "\n"
#define print(arr) All(x,arr) cout<<x<<" "; cout<<nl
#define sz(x) (int)x.size()
#define all(v) v.begin(),v.end()
#define vdsort(v) sort(v.begin(),v.end(),greater<int>())
#define F first
#define S second
#define mod 1000000007
const int MAXN=100001;
int spf[MAXN];
int gcd(int x, int y){ return y?gcd(y,x%y):x; }

void precal(){  
    spf[1] = 1; 
    for (int i=2; i<MAXN; i++)  spf[i] = i; 
    for (int i=4; i<MAXN; i+=2) spf[i] = 2; 
    for (int i=3; i*i<MAXN; i++) { 
        if (spf[i] == i) 
            for (int j=i*i; j<MAXN; j+=i) 
                if (spf[j]==j)  spf[j] = i; 
    } 
} 
vector<int> getFactorization(int x){
    vector<int> ret; 
    while (x != 1) { 
        ret.push_back(spf[x]); 
        x = x / spf[x]; 
    } 
    return ret; 
}

ll exp(ll n, ll m){
    ll a = 1;
    while (m){
        if (m & 1) a = (a * n % mod) % mod;
        m /= 2;
        n = (n*n) % mod;
    }
    return a;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    // freopen("input.txt","r",stdin); freopen("output.txt","w",stdout);
    int n,t=1;
    // cin>>t;
    while(t--){
        cin>>n;
        cout<<(n*360/gcd(360,n))/n<<nl;;
    }
    return 0;
}