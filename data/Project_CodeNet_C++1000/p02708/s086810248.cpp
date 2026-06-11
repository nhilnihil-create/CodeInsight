#include <bits/stdc++.h>
#define ll long long 
using namespace std;

ll sum(ll n){
    return ((n + 1)*n)/2;
}
int main() {
    ll n, k, mod = 1e9 + 7, ans = 0;
    cin >> n >> k;
    ll lb = sum(k), ub = 0;
    for(int i = k; i <= n + 1; i++){
        ans += sum(n) - sum(n - i) - sum(i - 1) + 1;
		ans %= mod;
    }
    cout << ans << endl;
    return 0;
}