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
ll mod=1e9+7;
const int MAX = 10000;
const int MOD = 1000000007;
long long fac[MAX], finv[MAX], inv[MAX];

void COMinit() {// テーブルを作る前処理
	fac[0] = fac[1] = 1;
	finv[0] = finv[1] = 1;
	inv[1] = 1;
	for (int i = 2; i < MAX; i++){
		fac[i] = fac[i - 1] * i % MOD;
		inv[i] = MOD - inv[MOD % i] * (MOD / i) % MOD;
		finv[i] = finv[i - 1] * inv[i] % MOD;
	}
}

long long COM(int n, int k){ // 二項係数:nCk計算
	if (n < k) return 0;
	if (n < 0 || k < 0) return 0;
	return fac[n] * (finv[k] * finv[n - k] % MOD) % MOD;
}
int main(){
	int k,n;
	COMinit();
	ll ans=1LL;
	cin >>n>>k;

	n-=k;
	ans*=n;
//	cout<<n<<endl;
	for(int i=1;i<=k;i++){
		ans=COM(n+1,i)%mod;
	//	clog<<n+1<<" "<<i<<"--";
		if(i!=k){
			ans*=COM(k-1,i-1)%mod;
		//	clog<<i<<" "<<k-i<<"--";
			// i, k-i
		}
		cout << ans%mod<< endl;
	//	clog<<endl;
	}
}
/*
  5 3   2,3
  |ooo|

  oo

  |o

  ||
2000 3
2 0
2 1
3 0
*/