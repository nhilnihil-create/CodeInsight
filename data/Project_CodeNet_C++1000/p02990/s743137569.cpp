//#include <bits/stdc++.h>
#include <stdio.h>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <vector>
#include <map>
#include <unordered_map>
#include <set>
#include <tuple>
#include <string>
#include <algorithm>
#include <functional>
#include <queue>
#include <stack>
#include <cmath>
#include <bitset>

using namespace std;
using ll=long long;
using intpair=pair<int,int>;
using intpv=vector<intpair>;
using llpair=pair<ll,ll>;
using llpv=vector<llpair>;
using intvec=vector<int>;
using llvec=vector<ll>;
using intq=queue<int>;
using llq=queue<ll>;
using intmat=vector<intvec>;
using llmat=vector<llvec>;
using pairmat=vector<llpv>;

template<typename T>
using matrix=vector<vector<T>>;
template<typename T>
using pque=priority_queue<T>;
template<typename T>
using lpque=priority_queue<T,vector<T>,greater<T>>;

#define PI 3.141592653589793
#define INTINF 1<<30
#define LLINF 1LL<<60
#define MPRIME 1000000007
#define MPRIME9 998244353

#define pushb push_back
#define fi first
#define se second

#define setpr fixed<<setprecision(15)
#define iter(name) decltype(name)::iterator
#define all(name) name.begin(),name.end()
#define rall(name) name.rbegin(),name.rend()
#define gsort(vbeg,vend) sort(vbeg,vend,greater<>())
#define init(v,size) v.resize(size); for(auto &a__: v) cin>>a__
#define matin(mat,H,W) for(int i__=0; i__<H; i__++)for(int j__=0; j__<W; j__++) cin>>mat[i__][j__]
#define out(n) cout<<n<<endl

template<class T> inline bool chmin(T& a, T b) {
	if (a > b) {
		a = b;
		return true;
	}
	return false;
}

template<class T> inline bool chmax(T& a, T b) {
	if (a < b) {
		a = b;
		return true;
	}
	return false;
}

template<class T> inline void outmat(T& a, int y, int x) {
	for(int i=0; i<y; i++) {
		for(int j=0; j<x; j++) cout<<a[i][j]<<" ";
		cout<<endl;
	}
}

ll GCD(ll a, ll b) { //最大公約数
	if(a==0||b==0) return 0;
	if(a<b) swap(a,b);
	ll tmp = a%b;
	while(tmp!=0) {
		a = b;
		b = tmp;
		tmp = a%b;
	}
	return b;
}

ll binpow(ll a, ll ex, ll p) { //繰り返し二乗法
	ll result=1;
	while(ex>0) {
		if(ex&1) result=result*a%p;
		ex>>=1;
		a=a*a%p;
	}
	return result;
}

ll Fact(ll x, ll p) { //階乗
	ll f=1;
	for(ll i=2; i<=x; i++) {
		f*=i;
		f%=p;
	}
	return f;
}

int DigitNum(ll n) { //桁数
	int digit=0;
	ll div=1LL;
	while(n/div) {
		digit++;
		div*=10;
	}
	return digit;
}


llvec fact,inv,factinv;
void prenCrP(ll n, ll p) {
	fact.resize(n+1);
	inv.resize(n+1);
	factinv.resize(n+1);
	fact[0]=fact[1]=inv[1]=factinv[0]=factinv[1]=1LL;
	for(ll i=2LL; i<=n; i++) {
		fact[i]=fact[i-1]*i%p;
		inv[i]=p-inv[p%i]*(p/i)%p;
		factinv[i]=factinv[i-1]*inv[i]%p;
	}
}
ll nCrP(ll n, ll r, ll p) { // mod pにおけるnCr
	if (r > n) return 0;
	return fact[n]*factinv[r]%p*factinv[n-r]%p;
}


int N,K,R;

void input() {
	cin>>N>>K;
	R=N-K;
}

void solve() {
	prenCrP(2500,MPRIME);
	for(int i=1; i<=K; i++) {
		int b=K-i, r=R-i+1;
		ll res=nCrP(b+i-1,i-1,MPRIME)*nCrP(r+i,i,MPRIME)%MPRIME;
		cout<<res<<endl;
	}
}

int main() {
	while(1) {
		input();
		solve();
		break;
	}
}
