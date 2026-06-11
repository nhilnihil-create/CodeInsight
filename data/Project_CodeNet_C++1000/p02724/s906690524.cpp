#include <bits/stdc++.h>

#pragma GCC target ("avx2")
#pragma GCC optimize("O3")
#pragma GCC optimization ("unroll-loops")

using namespace std;

#define all(x) (x).begin(), (x).end()

typedef long long ll;

void solve(){
	ll x;
	cin >> x;
	ll hap = 0;
	hap += (x / 500) * 1000;
	x -= (x / 500) * 500;
	hap += (x / 5) * 5;
	cout << hap;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    solve();
    
    return 0;
}
