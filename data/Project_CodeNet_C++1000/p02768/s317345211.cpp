#include <math.h>
#include <assert.h>
#include <algorithm>
#include <set>
#include <iostream>
#include <vector>
#include <queue>
#include <map>
#include <string>
#include <cstring>
#include <functional>
#include <stack>
#include <array>
#include <random>
#include <chrono>
#include <climits>
#include <bitset>
using namespace std ;
#define ld long double
#define int long long
#define ii pair<int,int>
#define FAST_IO ios_base::sync_with_stdio(false) ;cin.tie(NULL);cout.tie(NULL); clock_t beg = clock()
#define dbg(x) cerr << #x << " is " << x << endl;
#define ms(x,a) memset(x,(int)(a),sizeof(x))
#define all(x) (x).begin(), (x).end()
#define sz(x) ((int)(x).size())
#define vi vector<int >
#define pb push_back
#define endl '\n'
#define ff first
#define ss second
const int N = 3e5+7 ;
//const int INF = 1e18 ;
const int MOD = 1e9 + 7 ;
vector<int> fact;
vector<int> ifact;
vector<int> inv;
vector<int> pow2;
//const int MOD = 998244353;
int add(int a, int b)
{
	a+=b;
	while(a>=MOD) a-=MOD;
	return a;
}
void radd(int &a, int b)
{
	a=add(a,b); 
}
int mult(int a, int b)
{
	return (a*1LL*b)%MOD;
}
void rmult(int &a, int b)
{
	a=mult(a,b);
}
int modpow(int a, int b)
{
	int r=1;
	while(b)
	{
		if(b&1) r=mult(r,a);
		a=mult(a,a);
		b>>=1;
	}
	return r;
}
int choose(int a, int b)
{
	if(a<0||b<0) return 0;
	if(a<b) return 0;
	if(b==0) return 1;
	if(a==b) return 1;
	return mult(fact[a],mult(ifact[b],ifact[a-b]));
}
int inverse(int a)
{
	return modpow(a,MOD-2);
}
void init(int _n)
{
	fact.clear(); ifact.clear(); inv.clear(); pow2.clear();
	fact.resize(_n+1);
	ifact.resize(_n+1);
	inv.resize(_n+1);
	pow2.resize(_n+1);
	pow2[0]=1;
	ifact[0]=1;
	fact[0]=1;
	for(int i=1;i<=_n;i++)
	{
		pow2[i]=add(pow2[i-1],pow2[i-1]);
		fact[i]=mult(fact[i-1],i);
		//ifact[i]=mult(ifact[i-1],inv[i]);
	}
	ifact[_n] = inverse(fact[_n]);
	for(int i=_n-1;i>=1;i--)
	{
		ifact[i] = mult(ifact[i + 1], i + 1);
	}
	for(int i=1;i<=_n;i++)
	{
		inv[i] = mult(fact[i-1],ifact[i]);
	}
}


void solve(){
	int n , a , b ;
	cin >> n >> a >> b ;
	int tot = modpow(2,n) ;
	radd(tot,MOD-1) ;
	int denom = 1 ;
	int num = 1 ;
	int nn = n ;
	for(int i = 1 ; i <= a ; i++){
		rmult(denom, i) ;
		rmult(num,nn--) ;
	}
	radd(tot,MOD-mult(num,inverse(denom))) ;
	nn = n ;
	denom = 1 ;
	num = 1 ; 
	for(int i = 1 ; i <= b ; i++){
		rmult(denom, i) ;
		rmult(num,nn--) ;
	}
	radd(tot, MOD-mult(num,inverse(denom))) ;
	cout << tot ;
}

int32_t main(){
	FAST_IO ;
	int t = 1 ;
	//init(N) ;
//	cin >> t ;
	while(t--){
		solve() ;
	}
    cerr << "\nExecution time: " << (clock() - beg) / 1000 << '\n';
}
