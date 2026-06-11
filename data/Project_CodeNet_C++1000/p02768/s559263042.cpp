#include <bits/stdc++.h>
using ll = long long;
using namespace std;
#define rep(i,n) for(int i=0, i##_len=(int)(n); i<i##_len; i++)
#define reps(i,n) for(int i=1 , i##_len=(int)(n);i<=i##_len;i++)
#define rrep(i,n) for(int i=((int)(n)-1);i>=0;i--)
#define rreps(i,n) for(int i=((int)(n));i>0;i--)
#define repi(i,x) for(auto i=(x).begin(),i##_fin=(x).end();i!=i##_fin;i++)
#define all(x) (x).begin(), (x).end()
#define F first
#define S second
#define mp make_pair
#define pb push_back
#define solve(a) ((a)?"Yes":"No")
typedef vector<int> Vi;
typedef vector<Vi> VVi;
typedef pair<int , int> Pi;
typedef vector<Pi> VPi;
typedef vector<long long> V;
typedef vector<V> VV;
typedef pair<long long , long long> P;
typedef vector<P> VP;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1;} return 0;}
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1;} return 0;}
const long long INFLL = 1LL<<60;
const int INF = 1<<30;
const double PI=acos(-1);
ll mod=1e9+7LL;
long long modpow(long long a, long long n, long long mod=(1LL<<62)){
	long long res = 1;
	while (n > 0){
		if (n & 1)
		res = res * a % mod;
		a = a * a % mod;
		n >>= 1;
	}
	return res;
}
long long modinv(long long a, long long m) {
	long long b = m, u = 1, v = 0;
	while (b) {
		long long t = a / b;
		a -= t * b; swap(a, b);
		u -= t * v; swap(u, v);
	}
	u %= m;
	if (u < 0) u += m;
	return u;
}
int main(){
	ll n,a,b;
	ll ans=0LL;
	cin >>n>>a>>b;
	ans=modpow(2LL,n,mod)-1LL;
	//clog<<ans<<endl;
	//if (ans < 0)ans += mod;
	V fact(200010,1LL);
	for(ll i=1LL;i<200002;i++){
		fact[i]*=fact[i-1]*i%mod;
	}
	ll cnt=1LL;
	//clog<<"A"<<endl;
	for(ll i=0LL;i<a;i++){
		cnt*=(n-i);
		cnt%=mod;
	}
	cnt*=modinv(fact[a],mod);
	cnt%=mod;
//	clog<<cnt<<endl;
	ans-=cnt;
	if (ans < 0)ans += mod;
	ans%=mod;
	cnt=1ll;
	for (ll i = 0LL; i < b; i++)
	{
		cnt *= (n - i);
		cnt %= mod;
	}
	cnt *= modinv(fact[b], mod);
	cnt%=mod;
	//clog << cnt << endl;
	ans-=cnt;
	if(ans <0)ans += mod;
	ans %= mod;
	cout<<ans<<endl;
}
// 4 1 3
//0(1) 1(4) 2(6) 3(4) 4(1) = 16 - 2^4