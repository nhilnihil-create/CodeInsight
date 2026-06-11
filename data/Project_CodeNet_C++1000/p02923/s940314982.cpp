#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i< (n); i++)
using ll = long long;
using namespace std;

int main(){
	int N;
	cin >> N;
	ll H[N];
	rep(i,N) cin >> H[i];
	int ans = 0;
	int tmp = 0;
	for (int i = N-2; i >=0; i--) {
		if (H[i]>=H[i+1]) {
			tmp++;
			ans = max(ans,tmp);
		}
		else tmp = 0;
	}
	cout << ans << endl;
	return 0;
}
