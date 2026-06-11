#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
#define all(t) t.begin(), t.end()
#define inrange(i, a, b) (((i)>= min((a), (b))) && ((i) <= max((a), (b))))
typedef vector<ll> vi;
#define fi first
#define se second
const ll inf = 9e18;
const ll mod = 1e9 + 7;
const ll N = 2001;

ll modfac[N];
ll modfacinv[N];
ll invsi[N];

ll power(ll x, ll y, ll M = inf){
    ll ans = 1;
    x %= M;
    while(y){
        if(y&1)
            ans = (x * ans) % M;

        x = (x * x) % M;
        y >>= 1;
    }
    return ans;
}
ll modInverse(ll n) {
    return power(n, mod-2, mod);
}
ll spower(ll x, string s, ll M) {
    x %= M;
    ll ans = 1 % M;
    ll now = x;
    for (ll i = (ll)s.size() - 1; i >= 0; i--) {
        ans = (ans * power(now, s[i] - '0', M)) % M;
        now = power(now, 10, M);
    }
    return ans;
}
inline ll mul(ll a, ll b){ return (a * b) % mod; }
inline ll sub(ll a, ll b){ ll c = a - b; if(c < 0) c += mod; return c; }
inline ll add(ll a, ll b){ ll c = a + b; if(c > mod) c -= mod; return c; }
inline ll divi(ll a, ll b){ return mul(a, modInverse(b)); }

void simake(){
	invsi[0]=1;
	invsi[1]=1;
	for(ll i=2;i<N;i++)
	{
		invsi[i]=mul(invsi[mod%i], (mod-(mod/i)));
	}
}
void factmod(){
    modfac[0]=1;
	modfac[1]=1;
	for(ll i=2;i<N;i++)
	{
		modfac[i]=mul(i, modfac[i-1]);
	}
}
void factmodinv(){
	modfacinv[0]=1;
	modfacinv[1]=1;
	for(ll i=2;i<N;i++)
	{
		modfacinv[i]=mul(invsi[i], modfacinv[i-1]);
	}
}
ll nCrm(ll n,ll r){
	return mul(mul(modfac[n], modfacinv[r]), modfacinv[n-r]);
}

int main() {
	simake();
    factmod();
    factmodinv();
    
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

	ll n, r;
	cin>>n>>r;
	for(int i=1;i<=r;i++){
		if (n-r+1 >= i)
			cout<<mul(nCrm(n-r+1, i), nCrm(r-1, i-1))<<"\n";
  		else
		  	cout<<"0\n";
	}
	
	return 0;
}
