//2020年4月17日現在

#include<stdio.h>
#include<cmath>
#include<math.h>
#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
#include<complex>
#include<queue>
#include<set>
#include<utility>
#include<iomanip>
#include<limits>
#include<thread>
#include<map>
#include<stack>
#include<numeric>
#include<cassert>
#include<random>
#include<chrono>
#include<unordered_set>
#include<unordered_map>
#include<fstream>
#include<list>
#include<functional>
#include<bitset>
#include<tuple>
#include <cstdio>
#include <atcoder/convolution>
#include <atcoder/modint>
#include <atcoder/dsu>
#include <atcoder/fenwicktree>

using namespace std;
using namespace atcoder;

template <class... A>
void prints() { cout << "\n"; }
template <class... A>
void prints_rest() { cout << "\n"; }
template <class T, class... A>
void prints_rest(const T &first, const A &... rest) { cout << " " << first; prints_rest(rest...); }
template <class T, class... A>
void prints(const T &first, const A &... rest) { cout << first; prints_rest(rest...); }
template <class T, class... A>
void printd(const T &first, const A &... rest) { cout << fixed << setprecision(15) << first; prints_rest(rest...); }


namespace {
	// printElems(&a[0], &a[n]);　みたいな感じで使う。
	void printElems(const int* begin, const int* end)
	{
		for (const int* p = begin; p != end; ++p) {
			cout << *p << ' ';
		}
		cout << endl;
	}
}

#define rep(i,n) for(ll i=0; i<n; i++)
#define rep1(i,n) for(ll i=1; i<n+1; i++)
#define repr(i,n) for(ll i=n-1; i>=0; i--)
#define repr1(i,n) for(ll i=n; i>0; i--)
#define FOR(i,j,n) for(ll i=j; i < n; i++)
#define souatari(i,j,n) rep1(i,n-1)rep(j,i)
#define souatari1(i,j,n) for(ll i=2; i<n+1; i++)rep1(j,i-1)
#define mp make_pair
#define F first
#define S second
#define elif else if

typedef long long ll;
typedef vector<int>  vi;
typedef vector<vi>  vvi;
typedef vector<ll> vll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<pii> vpii;
typedef array<ll,3> arr3;
typedef long double D;


const ll llinf =  numeric_limits<ll>::max();
const ll _llinf = numeric_limits<ll>::lowest();
const int inf = numeric_limits<int>::max();
const int _inf = numeric_limits<int>::lowest();
const double dinf = numeric_limits<double>::infinity();
//const ll MOD = 1000000007;
const ll MOD = 998244353;
const ll BIG = 1LL<<60;
const string yes = "Yes";
const string no = "No";

//----------------------------------------------

fenwick_tree<ll> f(500005);

int main(){
	int n,q;
	cin >> n >> q;
	rep(i,n){
		ll a;
		cin >> a;
		f.add(i,a);
	}
	vll ans;
	rep(i,q){
		ll t,u,v;
		cin >> t >> u >> v;
		if(t == 0){
			f.add(u,v);
		}
		else{
			ans.push_back(f.sum(u,v));
		}
	}
	for(ll x : ans){
		prints(x);
	}


	return 0;
}


