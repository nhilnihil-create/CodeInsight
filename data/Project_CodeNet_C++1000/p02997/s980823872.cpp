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



ll COM(int n,int k){//二項係数の計算
	if(n < k){
		return 0;
	}
	if (n < 0 || k < 0){
		return 0;
	} 
	return fac[n] * (finv[k] * finv[n - k] % mod) % mod;
}


int main(){
	int n,K;cin>>n>>K;
	COMinit();

	if (K > COM(n - 1,2)) cout << -1 << endl;
	else{
		vector<vector<bool>> g(n + 1,vector<bool> (n + 1,false));
		int m = 0;
		for(int i = 2; i <= n; i++) {
			g[1][i] = true;
			m++;
		}
		for(int i = 2; i <= n; i++) {
			for(int j = i + 1; j <= n; j++) {
				g[i][j] = true;
				m++;
			}
		}
		for(int i = 0; i < K; i++) {
			bool flag = true;
			for(int j = 2; j <= n; j++) {
				for(int k = j + 1; k <= n; k++) {
					if (g[j][k] && flag){
						g[j][k] = false;
						flag = false;
						m--;
					}
				}
			}
		}
		cout << m << endl;
		for(int i = 1; i <= n; i++) {
			for(int j = 1; j <= n; j++) {
				if (g[i][j])cout << i << " " << j << endl;
			}
		}
	}
	return 0;
}