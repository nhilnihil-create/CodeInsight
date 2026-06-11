#include <bits/stdc++.h>
#define ALL(v) v.begin(), v.end()
#define MOD 1000000007
#define MAX 510000
#define rep(i, n) for(int i = 0; i < (int)(n); i++)

using namespace std;
typedef long long ll;
typedef pair<int, int> P;

//cout << fixed << setprecision(10);//
//最小公倍数//
ll gcd(ll x, ll y) {
	if (x == 0) return y;
	return gcd(y%x, x);
}
ll lcm(ll x, ll y) { return x * y / gcd(x, y); }

//逆元mod(mを法とするaの逆元)//
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

//Cmonp//
ll fac[MAX], finv[MAX], inv[MAX];

// テーブルを作る前処理
void COMinit() {
	fac[0] = fac[1] = 1;
	finv[0] = finv[1] = 1;
	inv[1] = 1;
	for (int i = 2; i < MAX; i++) {
		fac[i] = fac[i - 1] * i % MOD;
		inv[i] = MOD - inv[MOD%i] * (MOD / i) % MOD;
		finv[i] = finv[i - 1] * inv[i] % MOD;
	}
}

// 二項係数計算
ll COM(int n, int k) {
	if (n < k) return 0;
	if (n < 0 || k < 0) return 0;
	return fac[n] * (finv[k] * finv[n - k] % MOD) % MOD;
}

////////////////////////////////////////////////////////////////////

struct UnionFind {
	vector<ll> par,siz; // par[i]:iの親の番号　(例) par[3] = 2 : 3の親が2

	UnionFind(ll N) : par(N),siz(N, 1LL) { //最初は全てが根であるとして初期化
		for (ll i = 0; i < N; i++) par[i] = i;
	}
   


	ll root(ll x) { // データxが属する木の根を再帰で得る：root(x) = {xの木の根}
		if (par[x] == x) return x;
		return par[x] = root(par[x]);
	}

	void unite(ll x, ll y) { // xとyの木を併合
		ll rx = root(x); //xの根をrx
		ll ry = root(y); //yの根をry
		if (rx == ry) return; //xとyの根が同じ(=同じ木にある)時はそのまま
		if(siz[rx]<siz[ry]) swap(rx,ry);
        siz[rx]+=siz[ry];
        par[ry] = rx; //xとyの根が同じでない(=同じ木にない)時：xの根rxをyの根ryにつける
	}

	bool same(ll x, ll y) { // 2つのデータx, yが属する木が同じならtrueを返す
		ll rx = root(x);
		ll ry = root(y);
		return rx == ry;
	}

    ll size(ll x){
        return siz[root(x)];
    }
};

int main() {
ll n,k;
cin>>n>>k;

k=(n-1)*(n-2)/2-k;
if(k<0){
    cout<<-1<<endl;
    return 0;}


int edge[n+1][n+1];
for(int i=1;i<=n;i++){
    for(int j=1;j<=n;j++){
if(i>=j){
    edge[i][j]=-5;
    continue;
}
if(i==1){
    edge[i][j]=1;
}
if(i!=1){
    edge[i][j]=0;
}
    }
}
  
  


int fin=0;
ll cnt=0;
for(int i=1;i<=n;i++){
    for(int j=1;j<=n;j++){
        if(cnt==k){fin=1;
        break;
        }
        else{
            if(edge[i][j]==0){
                cnt++;
                edge[i][j]=1;
            }
        }

    }
    if(fin) break;
}

cout<<k+n-1<<endl;
for(int i=1;i<=n;i++){
    for(int j=1;j<=n;j++){
        if(edge[i][j]==1){
            cout<<i<<" "<<j<<endl;

        }
    }
}
return 0;

}