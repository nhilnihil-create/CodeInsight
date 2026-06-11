#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll mod = 1000000007;
int main(){
    ll n, K; cin >> n >> K;
    ll res = 0;
    for(ll k=K; k<=n+1; ++k){
        ll a = (k-1)*k/2, b = (2*n-k+1)*k/2;// cout << a << "," << b << endl;
        res += (b-a+1)%mod;
    }
	res %= mod;
    cout << res << endl;
    return 0;
}