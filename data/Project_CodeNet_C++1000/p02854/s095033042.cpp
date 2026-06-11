#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i< (n); i++)
using ll = long long;
using namespace std;

int main(){
	int N;
	cin >> N;
	ll A[N];
	ll tot = 0;
	rep(i,N) {
		cin >> A[i];
		tot += A[i];
	}
	ll left = 0;
	int k = 0;
	while (left < tot/2) {
		left += A[k];
		k++;
	}
	ll right = tot - left;
	ll ans = left -right;
	left -= A[k-1];
	right = tot - left;
	ans = min(ans, right-left);
	cout << ans << endl;
	return 0;
}
