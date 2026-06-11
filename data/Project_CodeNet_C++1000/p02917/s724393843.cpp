#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;

const int INF = 1001001001;
int main(){
	int n;
	cin >> n;
	vector<int> b(n-1);
	rep(i,n-1) cin >> b[i];
	vector<int> a(n,INF);
	rep(i,n-1){
		a[i] = min(a[i],b[i]);
		a[i+1] = min(a[i+1],b[i]);
	}
	int ans = 0;
	rep(i,n) ans += a[i];
	cout << ans << endl;
	return 0;
}