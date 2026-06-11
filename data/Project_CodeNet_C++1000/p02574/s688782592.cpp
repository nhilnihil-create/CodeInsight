#pragma GCC target("avx2")
#pragma GCC optimize("O3")
#pragma GCC optimize("unroll-loops")
#define _DEBUG
#include "bits/stdc++.h"
#define CHOOSE(a) CHOOSE2 a
#define CHOOSE2(a0,a1,a2,a3,a4,x,...) x
#define debug_1(x1) cout<<#x1<<": "<<x1<<endl
#define debug_2(x1,x2) cout<<#x1<<": "<<x1<<", "#x2<<": "<<x2<<endl
#define debug_3(x1,x2,x3) cout<<#x1<<": "<<x1<<", "#x2<<": "<<x2<<", "#x3<<": "<<x3<<endl
#define debug_4(x1,x2,x3,x4) cout<<#x1<<": "<<x1<<", "#x2<<": "<<x2<<", "#x3<<": "<<x3<<", "#x4<<": "<<x4<<endl
#define debug_5(x1,x2,x3,x4,x5) cout<<#x1<<": "<<x1<<", "#x2<<": "<<x2<<", "#x3<<": "<<x3<<", "#x4<<": "<<x4<<", "#x5<<": "<<x5<<endl
#ifdef _DEBUG
#define debug(...) CHOOSE((__VA_ARGS__,debug_5,debug_4,debug_3,debug_2,debug_1,~))(__VA_ARGS__)
#else
#define debug(...)
#endif
#define rep(index,num) for(int index=0;index<(int)num;index++)
#define rep1(index,num) for(int index=1;index<=(int)num;index++)
#define brep(index,num) for(int index=(int)num-1;index>=0;index--)
#define brep1(index,num) for(int index=(int)num;index>0;index--)
#define scan(argument) cin>>argument
#define prin(argument) cout<<argument<<endl
#define kaigyo cout<<endl
#define eps 1e-7
#define mp(a1,a2) make_pair(a1,a2)
#define ALL(a) (a).begin(),(a).end()
#define rALL(a) (a).rbegin(),(a).rend()
typedef long long ll;
typedef long double ld;
using namespace std;
typedef pair<ll,ll> pll;
typedef pair<int,int> pint;
typedef vector<int> vint;
typedef vector<ll> vll;
typedef vector<pint> vpint;
typedef vector<pll> vpll;
ll INFl=(ll)1e+18+1;
int INF=1e+9+1;
int A[1000001];
int insu[1000001]={};
bool prime_factor_decomp(ll n) {
    ll m = n;
    for (ll i = 2; i * i <= n; i++) {
        if (m % i != 0) continue;
        int c = 0;
        while (m % i == 0) c++, m /= i;
        insu[i]++;
		if(insu[i]>=2) return 0;
        //e.push_back(c);
    }
    if (m > 1) {
        insu[m]++;
		if(insu[m]>=2) return 0;
        //e.push_back(1);
    }
	return 1;
    //return mp(p, e);
}
ll gcd(ll x,ll y){
	if(y==0) return x;
	return gcd(y,x%y);
}
int main(){
	int N;
	scan(N);
	rep(i,N) scan(A[i]);
	bool flag=1;
	rep(i,N){
		if(A[i]!=1){
			bool f=prime_factor_decomp(A[i]);
			if(f==0){
				flag=0;
				break;
			}
		}
	}
	if(flag){
		prin("pairwise coprime");
	}
	else{
		int g=0;
		rep(i,N) g=gcd(g,A[i]);
		if(g==1) prin("setwise coprime");
		else prin("not coprime");
	}
	return 0;
}
