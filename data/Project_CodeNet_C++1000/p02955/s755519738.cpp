#include <iostream>
#include <string>
#include <cstdlib>
#include <cmath>
#include <vector>
#include <map>
#include <set>
#include <algorithm>
#include <queue>
#include <stack>
#include <functional>
#include <bitset>
#include <assert.h>
using namespace std;
typedef long long ll;
typedef vector<ll> vl;
typedef vector<vl> vvl;
typedef vector<char> vc;
typedef vector<string> vs;
typedef vector<bool> vb;
typedef vector<double> vd;
typedef pair<ll,ll> P;
typedef vector<P> vpl;
typedef tuple<ll,ll,ll> tapu;
#define rep(i,n) for(ll i=0; i<(n); i++)
#define REP(i,a,b) for(int i=(a); i<(b); i++)
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
const int inf = 1<<30;
const ll linf = 1LL<<62;
const int MAX = 510000;
ll dy[8] = {0,1,0,-1,1,-1,1,-1};
ll dx[8] = {1,0,-1,0,1,-1,-1,1};
const double pi = acos(-1);
const double eps = 1e-7;
template<typename T1,typename T2> inline bool chmin(T1 &a,T2 b){
	if(a>b){
		a = b; return true;
	}
	else return false;
}
template<typename T1,typename T2> inline bool chmax(T1 &a,T2 b){
	if(a<b){
		a = b; return true;
	}
	else return false;
}
template<typename T1,typename T2> inline void print2(T1 a, T2 b){cout << a << " " << b << endl;}
template<typename T1,typename T2,typename T3> inline void print3(T1 a, T2 b, T3 c){
	cout << a << " " << b << " " << c << endl;
}
const int mod = 1e9 + 7;
//const int mod = 998244353;

vl divisor(ll k){
	vl c;
	for(ll i=1; i*i<=k; i++){
		if(k % i == 0){
			c.push_back(i);
			if((k / i) != i){
				c.push_back(k/i);
			}
		}
	}
	sort(c.rbegin(), c.rend());
	return c;
}

int main(){
	ll n,k; cin >> n >> k;
	vl a(n); rep(i,n) cin >> a[i];
	ll sum = 0;
	rep(i,n) sum += a[i];
	vl div = divisor(sum);
	for(auto v : div){
		vl up, down;
		rep(i,n){
			if(a[i] % v == 0) continue;
			down.push_back(a[i] % v);
		}
		if(down.empty()){
			cout << v << endl;
			return 0;
		}
		sort(all(down));
		ll siz = down.size();
		vl acc(siz+1,0);
		for(ll i=siz-1; i>=0; i--){
			acc[i] = acc[i+1] + v - down[i];
		}
		ll cnt = 0;
		rep(i,siz-1){
			if(cnt == acc[i]) break;
			cnt += down[i];
		}
		if(cnt <= k){
			cout << v << endl;
			return 0;
		}
	}
}
