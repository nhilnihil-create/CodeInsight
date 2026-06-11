#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;

int main(){
	int n, k ,q;
	cin >> n >> k >> q;
	vector<int> ans(n,k);
	vector<int> wa(n);
	vector<int> a(q);
	rep(i,q) cin >> a[i];
	rep(i,q){
		wa[a[i] -1]++;
	}
	rep(i,n){
		ans[i] += wa[i];
		ans[i] -= q;
	}
	rep(i,n){
		if(ans[i] > 0) cout << "Yes" << endl;
		else cout << "No" << endl;
	}
}