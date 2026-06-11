#include<bits/stdc++.h>
using namespace std;

#define rep(i, n) for(int (i) = 0; (i) < (n); (i)++)
#define repn(i, n) for(int (i) = 1; (i) <= (n); (i)++)
#define repr(i, n) for(int (i) = (n-1); (i) >= 0; (i)--)
#define all(x) (x).begin(), (x).end()
#define lint long long
#define ulint unsigned long long
#define fi first
#define se second

typedef pair<lint, lint> P;
const lint MOD = 1e9+7;
const lint MOD9 = 998244353;
const lint INF = MOD * MOD;
const int MAX = 100005;

long long modpow(long long a, long long n) {
    long long res = 1;
    while (n > 0) {
        if (n & 1) res = res * a % MOD9;
        a = a * a % MOD9;
        n >>= 1;
    }
    return res;
}

int main(){
    int n; cin >> n;
    vector<lint> vec(MAX);
    rep(i, n-1) vec[i] = 0;
    lint d_max = 0;
    rep(i, n){
        lint d; cin >> d;
        if((i == 0 && d != 0) || (i != 0 && d == 0)){
            cout << 0 << endl;
            return 0;
        }
        if(d > d_max) d_max = d;
        vec[d]++;
    }
    lint ans = 1;
    repn(i, d_max-1){
        lint p = modpow(vec[i], vec[i+1]);
        ans = (ans * p) % MOD9;
    }
    cout << ans << endl;
}