#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <cmath>
#include <functional>
#include <set>
#include <numeric>
#define ll long long int
#define rep(i,n) for(int i=0;i<n;i++)
using namespace std;

int main() {
	ll N, flag=0, ans = 1;

	cin >> N;
	vector<ll> a(N);

	rep(i, N) cin >> a[i];

	rep(i, N){
		
		if (a[i]<=(ll)1000000000000000000/ans) {
			ans *= a[i];
		}
		else{
			flag = 1;
		}
		if (a[i] == 0) {
			cout << 0 << endl;
			return 0;
		}
	}

	if (flag == 1) cout << -1 << endl;
	if (flag == 0) cout << ans << endl;
	return 0;
}