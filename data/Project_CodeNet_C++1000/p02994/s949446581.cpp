#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;

int main() {
	int N, L;
	cin >> N >> L;
	int idx = 0;
	int tmp = 10000;
	int ans = 0;
	rep (i, N){
		ans += L + i;
		if (tmp*tmp > (L + i)*(L + i)){
			idx = i;
			tmp = L + i;
		}
	}
	cout << ans - (L + idx) << endl;
	return 0;
}
