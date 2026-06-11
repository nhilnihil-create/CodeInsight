#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;
typedef vector<int> vi;
typedef vector<double> vd;
typedef vector<ll> vl;
typedef vector<vi> vvi;
typedef vector<vl> vvl;
typedef pair<int,int> pii;
typedef pair<double, double> pdd;
typedef pair<ll, ll> pll;
typedef vector<pii> vii;
typedef vector<pll> vll;
typedef vector<pdd> vdd;

#define rep(i, n) for(int i = 0; i < (int)(n); i++)
#define mem(a,b) memset(a, b, sizeof(a) )
#define all(x) (x).begin(),(x).end()
#define INF 1000000000000
#define MOD 1000000007
#define PB push_back
#define MP make_pair
#define F first
#define S second

inline void normal(ll &a) { a %= MOD; (a < 0) && (a += MOD); }
inline ll modMul(ll a, ll b) { a %= MOD, b %= MOD; normal(a), normal(b); return (a*b)%MOD; }
inline ll modAdd(ll a, ll b) { a %= MOD, b %= MOD; normal(a), normal(b); return (a+b)%MOD; }
inline ll modSub(ll a, ll b) { a %= MOD, b %= MOD; normal(a), normal(b); a -= b; normal(a); return a; }
inline ll modPow(ll b, ll p) { ll r = 1; while(p) { if(p&1) r = modMul(r, b); b = modMul(b, b); p >>= 1; } return r; }
inline ll modInverse(ll a) { return modPow(a, MOD-2); }
inline ll modDiv(ll a, ll b) { return modMul(a, modInverse(b)); }

ll gcd(ll a,ll b){return b?gcd(b,a%b):a;}
ll lcm(ll a,ll b){return a/gcd(a,b)*b;}

int main(){
    int n,k,c;cin>>n>>k>>c;
    string s;cin>>s;
    vi dp(n+1,1);
    int f;
    rep(i,n){
        if(s[i]=='o'){f=i;break;}
    }
    for(int i=f+1;i<n;++i){
        if(s[i]=='o'&&i>=c+1){
            dp[i]=dp[i-c-1]+1;
        }
        else dp[i]=dp[i-1];
    }
    if(dp[n-1]>k){
        return 0;
    }
    map<int,int>a;
    int key,l;
    for(int i=n-1;i>=0;--i){
        if(s[i]=='o'){
            l=i;
            key=dp[i];
            a[key]++;
            break;
        }
    }
    vi ans;
    int w=l;
    for(int i=w-1;i>=f;--i){
        if(s[i]=='o'){
            if(key==dp[i])a[dp[i]]++;
            else{
                if(a[key]==1)ans.PB(key);
                key=dp[i];
                while(i+c>=l||s[i]!='o'){
                    i--;
                }
                a[key]++;
                l=i;
            }
        }
    }
    if(a[key]==1)ans.PB(key);
    reverse(all(ans));
    int cnt=0;
    for(int i=0;i<n;++i){
        if(ans[cnt]==dp[i]){
            cout<<i+1<<endl;
            cnt++;
            if(cnt==ans.size())break;
        }
    }
}