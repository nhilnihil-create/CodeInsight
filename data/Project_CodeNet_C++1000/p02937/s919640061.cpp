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

int ctoi(char c) {
	if (c >= '0' && c <= '9') {
		return c - '0';
	}
	return 0;
}

int main(){
    string s,t;cin>>s>>t;
    map<char,int>c;
    rep(i,s.size())c[s[i]]++;
    rep(i,t.size()){
        if(c[t[i]]==0){
            cout<<-1<<endl;
            return 0;
        }
    }
    vvi a;
    a.resize(26);
    rep(i,s.size()){
        a[s[i]-'a'].PB(i+1);
    }
    int d=a[t[0]-'a'][0];
    ll ans=d;
    for(int i=1;i<t.size();++i){
        int l=upper_bound(all(a[t[i]-'a']),d)-a[t[i]-'a'].begin();
        if(l==a[t[i]-'a'].size()){
            ans+=s.size()-d;
            ans+=a[t[i]-'a'][0];
            d=a[t[i]-'a'][0];
        }
        else{
            ans+=a[t[i]-'a'][l]-d;
            d=a[t[i]-'a'][l];
        }
    }
    cout<<ans<<endl;
}