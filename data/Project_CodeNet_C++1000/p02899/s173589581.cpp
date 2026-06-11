#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;

int main(){
	int n;
	cin >> n;
	vector<int> a(n);
	rep(i,n) cin >> a[i];
	vector<int> ans(n);
	rep(i,n){
		ans[a[i]-1] = i + 1;
	}
	rep(i,n) cout << ans[i] << endl;
}