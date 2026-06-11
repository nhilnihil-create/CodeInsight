#include<bits/stdc++.h>
using namespace std;
#define fs first
#define sc second
#define pb push_back
#define mp make_pair
#define eb emplace_back
#define ALL(A) A.begin(),A.end()
#define RALL(A) A.rbegin(),A.rend()
typedef long long ll;
typedef pair<ll,ll> P;
const ll mod=1000000007;
const ll LINF=1LL<<60;
const int INF=1<<30;

//nもrも10^5くらいのときにはこれ使うと良き
//二項係数の計算
const int MAX = 510000;
ll fac[MAX],finv[MAX],inv[MAX];

//テーブルの初期化
void COMinit(){
	fac[0] = fac[1] = 1;//階乗
	finv[0] = finv[1] = 1;//階乗の逆元
	inv[1] = 1;//逆元(1の逆元は1)
	for(int i = 2; i < MAX; i++) {
		fac[i] = fac[i - 1] * i % mod;//累積積的な感じ
		inv[i] = mod - inv[mod % i] * (mod / i) % mod;//inv[i] = iの逆元(mod mod)
		finv[i] = finv[i - 1] * inv[i] % mod;//階乗の逆元の計算
	}
}
ll per(ll n,ll k){
	return fac[n] * finv[n - k] % mod;
}


ll n,k;
vector<ll> v(100001,0LL);
vector<vector<ll>> g(200001);
void dfs(int x,int parent,int dist){
	for(int i = 0; i < g[x].size(); i++) {
		if (g[x][i] != parent){
			v[x]++;//parent の子の数
			dfs(g[x][i],x,dist + 1);
		}
	}
}

int main(){
	cin>>n>>k;
	for(int i = 0; i <  n - 1; i++) {
		ll a,b;cin>>a>>b;
		g[a].pb(b);
		g[b].pb(a);
	}
	g[0].pb(1);
	dfs(0,-1,0);
	ll ans = 1LL;
	COMinit();
	for(ll i = 1; i <= n; i++) {
		if (i == 1){
			if (k - 1 < v[1]){
				cout << 0 << endl;
				return 0;
			}
			ans *= (k * per(k - 1,v[1]) % mod);
		}
		else{
			if (k - 2 < v[i]){
				cout << 0 << endl;
				return 0;
			} 
			if (v[i] == 0){continue;}
			ans *= per(k - 2 ,v[i]);
			ans %= mod;
		}
	}
	cout << ans << endl;
	
	return 0;
}