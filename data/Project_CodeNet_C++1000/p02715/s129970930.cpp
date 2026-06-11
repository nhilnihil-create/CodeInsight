#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int N = 2e5 + 5, mod = 1e9 + 7;

int add(int a, int b){
    a = (a + mod) % mod;
    b = (b + mod) % mod;
    return (a + b) % mod;
}

int mul(int a, int b){
    a = (a + mod) % mod;
    b = (b + mod) % mod;
    return 1ll * a * b % mod;
}

int fp(int b, int p){
    if(!p) return 1;
    ll ret = fp(b, p >> 1);
    ret = ret * ret % mod;
    if(p&1) ret = ret * b % mod;
    return ret;
}

int kam[N];

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int n, k;
    cin >> n >> k;
    ll ans = fp(k, n);
    fill(kam, kam + N, 1);
    for(int i = 2; i <= k; i++){
        for(int j = i + i; j <= k; j += i) kam[j] += (i - kam[i]);
    }
    // for(int i = 2; i <= k; i++) cout << i << ' ' << kam[i] << '\n';
    for(int i = 2; i <= k; i++){
        ll x = i - kam[i];
        ans = add(ans, mul(x, fp(k / i, n)));
    }
    cout << ans;

    return 0;

}
