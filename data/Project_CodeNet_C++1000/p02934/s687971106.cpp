#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;

int main(){
	double n;
	cin >> n;
	vector<double> a(n);
	rep(i,n) cin >> a[i];
	double ans = 0;
	rep(i,n){
		ans += 1/a[i];
	}
	cout << fixed << setprecision(15) << 1/ans << endl;
}