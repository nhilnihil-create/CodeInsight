#include <bits/stdc++.h>

using namespace std;

#define REP(i,n) for(ll (i) = (0);(i) < (n);++i)
#define REV(i,n) for(ll (i) = (n) - 1;(i) >= 0;--i)
#define PB push_back
#define EB emplace_back
#define MP make_pair
#define FI first
#define SE second
#define SHOW1d(v,n) {REP(WW,n)cerr << v[WW] << ' ';cerr << endl << endl;}
#define SHOW2d(v,WW,HH) {REP(W_,WW){REP(H_,HH)cerr << v[W_][H_] << ' ';cerr << endl;}cerr << endl;}
#define ALL(v) v.begin(),v.end()
#define Decimal fixed<<setprecision(20)
#define INF 1000000000
#define LLINF 1000000000000000000LL
#define MOD 998244353

typedef long long ll;
typedef pair<ll,ll> P;

ll mp[555][555];
void dfs(int l, int r, int num){
	//cout << "dfs " << l << " " << r << " " << num << endl;
	if(r - l <= 1){
		mp[l][r] = num;
		mp[r][l] = num;
		return;
	}
	int mid = (l + r) / 2;
	for(int i = l;i <= mid;i++){
		for(int j = mid+1;j <= r;j++){
			mp[i][j] = num;
			mp[j][i] = num;
		}
	}
	dfs(l, mid, num + 1);
	dfs(mid + 1, r, num + 1);
}

int main(){
	cin.tie(0);cout.tie(0);ios::sync_with_stdio(false);
	ll n;cin >> n;
	dfs(0, n-1, 1);
	REP(i, n-1){
		REP(j, n){
			if(i < j)cout << mp[i][j] << " ";
		}
		cout << endl;
	}
	return 0;
}
