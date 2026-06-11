#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i< (n); i++)
using ll = long long;
using namespace std;

int main(){
	int L, R;
	cin >> L >> R;

	if (R-L+1 >= 2019) {
		cout << 0 << endl;
		return 0;
	}

	int ans = 2019;
	for (int i = L; i < R; i++){
		for (int j = i+1; j <= R; j++){
			int k = (i%2019)*(j%2019);
			k %= 2019;
			ans = min(ans, k);
		}
	}
	cout << ans << endl;
return 0;
}
