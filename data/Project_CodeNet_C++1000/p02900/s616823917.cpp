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
const int mxn = 1e6+5;
vector<bool>isComposite(mxn);
vll primes;

void seive(){
	isComposite[0]=isComposite[1]=1;
	for(ll i=2; i<mxn; i++){
		if(!isComposite[i]){
			primes.eb(i);
			for(ll j=2*i; j<mxn; j+=i)isComposite[i]=1;
		}
	}
	return;
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    //freopen("input.txt","r",stdin); freopen("output.txt","w",stdout);
	ll a,b; cin >> a >> b;
	ll gcd = __gcd(a,b);
	vll p;
	seive();
	for(auto x:primes){
		if(x>gcd)break;
		if(gcd%x==0)p.eb(x);
		while(gcd%x==0){
			gcd/=x;
		}
	}
	if(gcd>1)p.eb(gcd);
	cout << p.size()+1 << endl;
}
	
// READ & UNDERSTAND
// ll, int overflow, array bounds, memset(0)
// special cases (n=1?), n+1 (1-index)
// do smth instead of nothing & stay organized
// WRITE STUFF DOWN
