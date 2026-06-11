#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;

int main(){
	int n;
	cin >> n;
	vector<int> a(n+1);
	rep(i,n+1) cin >> a[i];
	vector<int> b(n);
	rep(i,n) cin >> b[i];
	ll ans = 0;
	rep(i,n+1){
		int x = min(a[i],b[i]);
		ans += x;
		b[i] -= x;
		int y = min(a[i+1],b[i]);
		ans += y;
		a[i+1] -= y;
	}
	cout << ans << endl;
}

// cout << fixed << setprecision(15) <<  << endl;