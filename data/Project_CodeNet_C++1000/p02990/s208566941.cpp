#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int N = 5e4 + 5, mod = 1e9 + 7;

int fact[N], inv[N];

int mul(int a, int b){
    a = (a + mod) % mod;
    b = (b + mod) % mod;
    return 1ll * a * b % mod;
}

int fp(int b, int p){
    if(!p) return 1;
    int ret = fp(b, p >> 1);
    ret = mul(ret, ret);
    if(p&1) ret = mul(ret, b);
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
    int n, k;
    cin >> n >> k;
    for(int i = 1; i <= k; i++){
        int kam = k - i;
        int tmp = n - k - i + 1;
        if(tmp < 0){
            cout << 0 << '\n';
            continue;
        }
        cout << mul(ncr(kam + i - 1, kam), ncr(tmp + i, i)) << '\n';
    }

    return 0;

}
