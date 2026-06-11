#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;

const int N = 2005;
const ll mod = 1000000007;

int ncr[N][N];

void pre(){
	memset(ncr, 0, sizeof(ncr));
	for(int n = 0; n < N; n++){
		ncr[n][0] = 1;
		for(int r = 1; r <= n; r++){
			ncr[n][r] = ncr[n - 1][r] + ncr[n - 1][r - 1];
			if(ncr[n][r] >= mod)ncr[n][r] -= mod;
		}
	}
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cout<<setprecision(32);

	pre();
	int n, k;
	cin>>n>>k;
	for(int i = 1; i <= k; i++){
		ll ans = ncr[k - 1][i - 1];
		ans *= ncr[n - k + 1][i];
		ans %= mod;
		cout<<ans<<'\n';
	}

	return 0;
}