#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define ll long long

int f(int n, int k){
	int ans = 0;
	while(0 < n){
		n /= k;
		ans++;
	}
	return ans;
}

int main(){
	int n, k;
	cin >> n >> k;

	int ans = f(n, k);
	cout << ans << endl;

	return 0;
}