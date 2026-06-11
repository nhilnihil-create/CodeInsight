#include "bits/stdc++.h"
#pragma GCC optimize("O3,Ofast,no-stack-protector,unroll-loops,fast-math")
#pragma GCC target ("avx,avx2")

using namespace std;

using ll = long long;
#define all(x) begin(x), end(x)

void solve(){

}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
	ll n; cin >> n;
	ll ans = 0;
	for(int i{1}; i<=n; i++){
		ans += (n-1)/i;
	}

	cout << ans << "\n";


}
