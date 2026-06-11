#include <bits/stdc++.h>
using namespace std;
typedef vector<int> vint;
#define rep(i,n) for (int i = 0; i < (int)(n); ++i)
#define be(v) (v).begin(), (v).end()

int main() {
	int A,B,m; cin >> A >> B >> m;
	vint a(A); vint b(B);
	int amin=100001;
	int bmin=amin;
	rep(i,A) {
		cin >> a[i];
		amin=min(amin,a[i]);
	}
	rep(i,B) {
		cin >> b[i];
		bmin=min(bmin,b[i]);
	}
	vint price(m);
	rep(i,m) {
		int x,y,c; cin >> x >> y >> c;
		price[i]=a[x-1]+b[y-1]-c;
	}
	sort(be(price));
	cout << min(price[0],amin+bmin) << endl;
}