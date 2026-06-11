#include <bits/stdc++.h>

using namespace std;

#define fi first
#define se second
#define eb emplace_back
#define mt make_tuple
#define all(x) (x).begin(), (x).end() 
#define MOD 1000000007

typedef long long ll;
typedef pair <int, int> ii;
typedef pair <ll, ll> pll;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef long double ld;

const ll INF=LLONG_MAX;
const int mxn=7e5+5;

void multi(ll &a, ll b){
	a%=MOD; b%=MOD; a*=b; a%=MOD;
}

void add(ll &a, ll b){
	a%=MOD; b%=MOD; a+=b; a%=MOD;
}

ll modpow(ll a, ll b){
	ll r = 1LL;
	while(b){
		if(b&1)multi(r,a);
		multi(a,a);
		b>>=1;
	}
	return r;
}

ll fact[mxn];
void init(){
	fact[0]=1LL;
	for(int i=1; i<mxn; i++){
		fact[i]=fact[i-1]*1LL*i%MOD;
	}
}

ll nCr(int x, int y){
	ll res = fact[x];
	multi(res,modpow(fact[y],MOD-2));
	multi(res,modpow(fact[x-y],MOD-2));
	return res;
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    //freopen("input.txt","r",stdin); freopen("output.txt","w",stdout);
    init();
	int x; int y;
	cin >> x >> y;
	ll t = x+y;
	if(t%3==0){
		t/=3;
		if(x<t||y<t){
			cout << 0 << endl;
		}else{
			cout << nCr(t,x-t) << endl;
		}
	}else{
		cout << 0 << endl;
	}
}
	
// READ & UNDERSTAND
// ll, int overflow, array bounds, memset(0)
// special cases (n=1?), n+1 (1-index)
// do smth instead of nothing & stay organized
// WRITE STUFF DOWN
