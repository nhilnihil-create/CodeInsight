#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int N = 5e3 + 5, b = 31, b2 = 37, mod = 1e9 + 7;

string s;
int n, inv[N], inv2[N], pw[N], pw2[N], val[N], val2[N];

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
    if(p == 0) return 1;
    int ret = fp(b, p >> 1);
    ret = mul(ret, ret);
    if(p&1) ret = mul(ret, b);
    return ret;
}

void pre(){
    int mul_inv = fp(b, mod - 2), mul_inv2 = fp(b2, mod - 2);
    inv[0] = inv2[0] = pw[0] = pw2[0] = 1;
    for(int i = 1; i < N; i++){
        pw[i] = mul(pw[i - 1], b);
        pw2[i] = mul(pw2[i - 1], b2);
        inv[i] = mul(inv[i - 1], mul_inv);
        inv2[i] = mul(inv2[i - 1], mul_inv2);
    }
}

pair<int, int> get_hash(int l, int r){
    int ret = val[r];
    if(l) ret = add(ret, -val[l - 1]);
    ret = mul(ret, inv[l]);

    int ret2 = val2[r];
    if(l) ret2 = add(ret2, -val2[l - 1]);
    ret2 = mul(ret2, inv2[l]);

    return {ret, ret2};
}

bool tmam(int len){
    map<pair<int, int>, int> mp;
    for(int i = 0; i + len - 1 < n; i++){
        int l = i, r = i + len - 1;
        auto x = get_hash(l, r);
        if(mp.find(x) == mp.end()){
            mp[x] = r;
        }
        else{
            if(mp[x] < l) return 1;
        }
    }
    return 0;
}

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    pre();
    cin >> n >> s;
    for(int i = 0; i < n; i++){
        val[i] = add(mul(pw[i], s[i] - 'a' + 1), i ? val[i - 1] : 0);
        val2[i] = add(mul(pw2[i], s[i] - 'a' + 1), i ? val2[i - 1]: 0);
    }
    int low = 0, high = n / 2, mid, ans = 0;
    while(high >= low){
        mid = low + high >> 1;
        if(tmam(mid)){
            ans = mid;
            low = mid + 1;
        }
        else high = mid - 1;
    }
    cout << ans;



    return 0;

}
