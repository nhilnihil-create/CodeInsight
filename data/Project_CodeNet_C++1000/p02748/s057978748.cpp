#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i< (n); i++)
using ll = long long;
using namespace std;

int main(){
	int A, B, M;
	cin >> A >> B >> M;
	int a[A+1], b[B+1], x[M], y[M], c[M];
	rep(i,A) cin >> a[i+1];
	rep(i,B) cin >> b[i+1];
	rep(i,M) cin >> x[i] >> y[i] >> c[i];
	int ans = 200000;

	rep(i,M) {
		int price = a[x[i]] + b[y[i]] - c[i];
		ans = min(ans, price);
	}
	sort(a+1,a+A+1);
	sort(b+1,b+B+1);
	ans = min(ans,a[1]+b[1]);

	cout << ans << endl;	

	return 0;
}
