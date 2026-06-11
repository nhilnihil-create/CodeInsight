#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;

int main(){
	double n,k;
	cin >> n >>k;
	vector<double> p(n);
	rep(i,n) cin >> p[i];
	double kitai = 0;
	vector<double> ans(n);
	rep(i,n) ans[i] = (p[i]+1)/2;
	rep(i,k) kitai += ans[i];
	double wa = kitai;
	rep(i,n-k+1){
		wa = wa - ans[i] + ans[i+k];
		kitai = max(kitai,wa);
	}

	cout << fixed << setprecision(15) <<  kitai << endl;
}

// cout << fixed << setprecision(15) <<  << endl;