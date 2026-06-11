#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pi;
typedef vector<ll> vi;
typedef vector<pi> vpi;
typedef long double ld;
const int inf = 1e9 + 7;
const int mod = 1e9 + 7;
const int maxn = 1e6 + 3;
#define pb push_back
#define mp make_pair
#define ff first
#define ss second
#define rep(i, a, b) for(int i = a; i < b; i++)
#define all(v) v.begin(),v.end()
#define rall(v) v.rbegin(),v.rend()
#define lb lower_bound
#define ub upper_bound
#define fact(n) rep(i, 1, n+1)ft.pb((ft[i-1]*i)%mod);
#define mod_in(a) exp(a, mod-2)
#define ncr(n, r) ((ft[n]*mod_in((ft[r]*ft[(n)-(r)])%mod))%mod)
#define deb(x) cout << #x << " " << x << endl;
#define flash ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl '\n'
ll prime[100002];
ll exp(ll a,ll b);
void sieve(ll n);
ll gcd(ll a ,ll b);
ll countdigit(ll n);

void solve(){
    ll n; cin >> n;
    ll L[n];
    rep(i,0,n){
        cin >> L[i];
    }
    ll c=0;
    sort(L,L+n);
    rep(i,0,n){
        rep(j,i,n){
            if(i!=j){
                rep(k,j,n){
                    if(k!=j){
                        if(L[k]<L[i]+L[j]&&L[i]!=L[j]&&L[j]!=L[k]){
                            c++;
                        }
                    }
                }
            }
        }    
    }
    cout<<c<<endl;
}
int main()
{
    ll t=1;
    //cin >> t;
    while(t--) {
        solve();
     
    }

}


//
//
//
//
//
// IMPORTANT FUNCTIONS
ll exp(ll a, ll b) {
	int res=1;
	while(b) {
		if(b&1)
			res=(res*a)%mod;
		a=(a*a)%mod;
		b>>=1;
	}
	return res;
}
ll gcd(ll a,ll b){
    if(a==0)return b;
    return gcd(b%a,a);
}
void sieve(ll n) {
    for(ll i=0;i<=n;i++) {
        prime[i]=1;
    }
    prime[0]=0;prime[1]=0;
    for(ll i=2;i<=n;i++) {
        if(prime[i]==1) {
            for(ll j=2;i*j<=n;j++) {
                prime[i*j]=0;
            }
        }
    }
}
ll countdigit(ll  n)
{
    return floor(log10(n) + 1);
}
