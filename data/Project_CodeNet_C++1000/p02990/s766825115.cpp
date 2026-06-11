#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ld = long double;
const ll MOD=1e9+7;

vector<long long> inv,finv;
void COMinit(long long siz) {
    long long buf=5;
    inv.resize(siz+buf);
    finv.resize(siz+buf);

    finv[0]=finv[1]=1;
    inv[1]=1;

    for (int i = 2; i < siz+buf; i++){
    inv[i] = MOD - inv[MOD%i] * (MOD / i) % MOD;
    finv[i] = finv[i - 1] * inv[i] % MOD;
    }
}

// 二項係数計算
long long COM(int n, int k){
    if (n < k) return 0;
    if (n < 0 || k < 0) return 0;
    long long ans=1;
    for(long long i = n; i >= n-k+1; i--) {
        ans*=i;
        ans%=MOD;
    }
    ans*=finv[k];
    return ans%MOD;
}
//#define int long long
//signed main(){
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n,k;
    cin >> n >> k;
    COMinit(2000);
    ll ans;
    for(int i = 1; i <= k; i++) {
        ans=COM(k-1,i-1)*COM(n-k+1,i)%MOD;
        cout << ans << "\n";
    }

    return 0;
}