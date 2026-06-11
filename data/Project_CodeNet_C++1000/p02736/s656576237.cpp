//Let's join Kaede Takagaki Fun Club !!
#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#pragma GCC optimize("unroll-loops")
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
typedef pair<int,P> P1;
typedef pair<P,P> P2;
#define pu push
#define pb push_back
#define mp make_pair
#define eps 1e-7
#define INF 1000000000
#define fi first
#define sc second
#define rep(i,x) for(int i=0;i<x;i++)
#define repn(i,x) for(int i=1;i<=x;i++)
#define SORT(x) sort(x.begin(),x.end())
#define ERASE(x) x.erase(unique(x.begin(),x.end()),x.end())
#define POSL(x,v) (lower_bound(x.begin(),x.end(),v)-x.begin())
#define POSU(x,v) (upper_bound(x.begin(),x.end(),v)-x.begin())
#define all(x) x.begin(),x.end()
template<class T>
void dmp(T a){
	rep(i,a.size()) cout << a[i] << " ";
	cout << endl;
}
template<class T>
bool chmax(T&a, T b){
	if(a < b){
		a = b;
		return 1;
	}
	return 0;
}
template<class T>
bool chmin(T&a, T b){
	if(a > b){
		a = b;
		return 1;
	}
	return 0;
}
template<class T>
void g(T &a){
	cin >> a;
}
template<class T>
void o(const T &a,bool space=false){
	cout << a << (space?' ':'\n');
}
//ios::sync_with_stdio(false);
const ll mod = 1000000007;//998244353
template<class T>
void add(T&a,T b){
	a+=b;
	if(a >= mod) a-=mod;
}

int n,a[1000005];
string f;

ll C(int a,int b){
	if( (a&b) == b ) return 1;
	else return 0;
}

int main(){
	ios::sync_with_stdio(false);
	g(n); g(f);
	repn(i,n) a[i] = f[i-1] - '0';
	
	ll ans = 0;
	ll ans2 = 0;
	bool ex = 0;
	for(int i=0;i<n-1;i++){
		int v = a[i+2] - a[i+1];
		v = abs(v);
		
		ans += v * C(n-2, i);
		ans %= 2;
		if(v%2 == 1) ex = 1;
		else{
			ans2 += (v/2) * C(n-2, i);
			ans2 %= 2;
		}
	}
	if(ans == 1) puts("1");
	else if(ex) puts("0");
	else puts(ans2?"2":"0");
}
