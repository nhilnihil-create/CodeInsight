#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vint;
#define rep(i,n) for (int i = 0; i < (int)(n); ++i)
#define be(v) (v).begin(), (v).end()

int main() {
	int n; cin >> n;
	vint a(n);
	vint b(n);
	rep(i,n) {
		cin >> a[i];
		b[i]=a[i];
	}
	sort(be(b));
	reverse(be(b));
	int max1=b[0];
	int max2=b[1];
	rep(i,n) {
		if(a[i]==max1) cout << max2 << endl;
		else cout << max1 << endl;
	}
}