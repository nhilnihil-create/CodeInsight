#include <iostream>
#include <cmath>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

#define INF 1e9
#define MAXN 100005
#define MAXM 100005
#define MOD 998244353
#define ll long long
#define vi vector<int>
#define vll vector<long long>
#define rep(i,n) for(int i=0, i##_len=(n); i<i##_len; ++i)
#define pii pair<int, int>

ll ans = 1;
int N, maxVal = 0;
vi D;
map<ll, ll> mp;

// a^n mod を計算する
long long modpow(long long a, long long n, long long mod) {
    long long res = 1;
    while (n > 0) {
        if (n & 1) res = res * a % mod;
        a = a * a % mod;
        n >>= 1;
    }
    return res;
}

void solve(){
    rep(i, N){
        if((i == 0 && D[i] != 0) || (i != 0 && D[i] == 0)){
            cout << 0 << endl;
            return;
        }
        mp[D[i]]++;
        maxVal = max(maxVal, D[i]);
    }

    int prev = 1;

    rep(i, maxVal+1){
        if(mp[i] == 0){
            cout << 0 << endl;
            return;
        }
        ans *= modpow(prev, mp[i], MOD);
        prev = mp[i];
        ans %= MOD;
    }

    cout << ans << endl;
}

int main(){
    cin >> N;
    D.resize(N);

    rep(i, N) cin >> D[i];

    solve();
}
