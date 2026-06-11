#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int N = 2000 + 5, mod = 1e9 + 7;

int fact[N], inv[N];

int add(int a, int b){
    a = (a + mod) % mod;
    b = (b + mod) % mod;
    return (a + b) % mod;
}

ll mul(ll a, ll b){
    return a * b % mod;
}

int fp(int b, int p){
    if(!p) return 1;
    ll ret = fp(b, p >> 1);
    ret = ret * ret % mod;
    if(p&1) ret = ret * b % mod;
    return ret;
}

void pre(){
    fact[0] = inv[0] = 1;
    for(int i = 1; i < N; i++){
        fact[i] = mul(fact[i - 1], i);
        inv[i] = fp(fact[i], mod - 2);
    }
}

int ncr(int n, int r){
    int ret = mul(fact[n], inv[n - r]);
    return mul(ret, inv[r]);
}

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    pre();
    int n;
    cin >> n;
    int ans = 0;
    for(int i = 1; i; i++){
        int tmp = n - i * 3;
        if(tmp < 0) break;
        ans = add(ans, ncr(tmp + i - 1, i - 1));
    }
    cout << ans;


    return 0;
}
