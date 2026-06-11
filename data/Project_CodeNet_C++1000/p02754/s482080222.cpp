
#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<(int)n;i++)

int main() {
	int64_t N, b, r;
	cin >> N >> b >> r;
	int64_t ans = N/(b+r)*b;
	if (N%(b+r)==0)
	{
		cout << ans << endl;
	}
	else {
		ans += min(N % (b + r), b);
		cout << ans << endl;
	}
}
