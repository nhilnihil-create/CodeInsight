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
ll lcm(ll a,ll b){return a*b/gcd(a,b);}

int ctoi(char c) {
	if (c >= '0' && c <= '9') {
		return c - '0';
	}
	return 0;
}

int main(){
    string s;cin>>s;
    ll k;cin>>k;
    char n=s[0];
    vl c;
    ll cnt=0,ans=0;
    for(int i=0;i<s.size();++i){
        if(s[i]==n)cnt++;
        else{
            n=s[i];
            c.PB(cnt);
            cnt=1;
        }
    }
    c.PB(cnt);
    if(c.size()==1){
        cout<<s.size()*k/2<<endl;
        return 0;
    }
    ll m=0;
    if(s[0]==s[s.size()-1]){
        m=c[0]+c[c.size()-1];
        for(int i=1;i<c.size()-1;++i){
            ans+=c[i]/2*k;
        }
        ans+=c[0]/2+c[c.size()-1]/2+m/2*(k-1);
    }
    else{
        rep(i,c.size()){
            ans+=c[i]/2*k;
        }
    }
    cout<<ans<<endl;
}
