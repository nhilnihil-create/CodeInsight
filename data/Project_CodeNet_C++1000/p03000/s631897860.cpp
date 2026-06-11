#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vint;
#define rep(i,n) for (int i = 0; i < (int)(n); ++i)

int main() {
	int n,x; cin >> n >> x;
	vint l(n);
	int d=0,ans=1;
	rep(i,n) {
		cin >> l[i];
		d+=l[i];
		if(d<=x) ans++;
	}
	cout << ans << endl;
}