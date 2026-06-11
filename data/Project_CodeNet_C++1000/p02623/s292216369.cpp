#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> P;
#define rep(i,n) for (ll i = 0; i < (n); ++i)
#define vcout(v) rep(i,v.size()) cout << v[i] << " "; cout << endl
#define mcout(m) rep(j,m.size()){vcout(m[j]);}
const ll MOD = 1e9 + 7;

int mainsolve(){

	ll n,m,k;
	cin >> n >> m >> k;
	vector<ll> a(n), b(m);
	rep(i,n) cin >> a[i];
	rep(i,m) cin >> b[i];

	ll res = 0;
	ll sumA = 0, cntA = 0;
	ll sumB = 0, cntB = 0;

	// まず、Aから一冊も読まないと仮定
	while(true){
		if(sumB + b[cntB] > k) break;
		sumB += b[cntB];
		cntB++;
		if(cntB == m) break;
	}
	res = cntB;

	// Aから取る冊数を増やしていく
	rep(i,n){
		cntA++;
		sumA += a[i];
		while(sumA + sumB > k){
			cntB--;
			if(cntB < 0) break;
			sumB -= b[cntB];
		}

		if(cntB < 0) break;
		res = max(res, cntA + cntB);
	}

	cout << res << endl;
	
	return 0;
}

int main(){

	return mainsolve();
}