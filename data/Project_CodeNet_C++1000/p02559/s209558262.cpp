#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define P pair<ll,ll>
#define FOR(I,A,B) for(ll I = ll(A); I < ll(B); ++I)
#define FORR(I,A,B) for(ll I = ll((B)-1); I >= ll(A); --I)
#define TO(x,t,f) ((x)?(t):(f))
#define SORT(x) (sort(x.begin(),x.end())) // 0 2 2 3 4 5 8 9
#define POSL(x,v) (lower_bound(x.begin(),x.end(),v)-x.begin()) //xi>=v  x is sorted
#define POSU(x,v) (upper_bound(x.begin(),x.end(),v)-x.begin()) //xi>v  x is sorted
#define NUM(x,v) (POSU(x,v)-POSL(x,v))  //x is sorted
#define REV(x) (reverse(x.begin(),x.end())) //reverse
ll gcd_(ll a,ll b){if(a%b==0)return b;return gcd_(b,a%b);}
ll lcm_(ll a,ll b){ll c=gcd_(a,b);return ((a/c)*(b/c)*c);}
#define NEXTP(x) next_permutation(x.begin(),x.end())
const ll INF=ll(1e16)+ll(7);
//const ll MOD=1000000007LL;
const ll MOD=998244353;
#define out(a) cout<<fixed<<setprecision((a))
//tie(a,b,c) = make_tuple(10,9,87);
#define pop_(a) __builtin_popcount((a))
ll keta(ll a){ll r=0;while(a){a/=10;r++;}return r;}

class BIT{
public:
	vector<ll> bit;
	ll M;
	// 1-index
	BIT(ll M):
		bit(vector<ll>(M+1, 0)), M(M) {}

	ll sum(ll i) {
		if (!i) return 0;
		return bit[i] + sum(i-(i&-i));
	}

	void add(ll i, ll x) {
		if (i > M) return;
		bit[i] += x;
		add(i+(i&-i), x);
	}
};

int main(){

	ll N,Q;
	cin >> N >> Q;
	BIT bit(N+3);
	FOR(i,0,N){
		ll a;
		cin >> a;
		bit.add(i+1,a);
	}


	FOR(q,0,Q){
		ll a,b,c;
		cin >> a >> b >> c;
		b++,c++;
		if(a){
			cout << bit.sum(c-1) - bit.sum(max(0LL,b-1)) << endl;
		}else{
			bit.add(b,c-1);
		}
	}
}

