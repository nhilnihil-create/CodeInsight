#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, start, n) for (int i = (int)(start); i < (int)(n); ++i)
#define all(a) a.begin(), a.end()

const int MOD = 1e9+7;

int main(){
    int N;
    cin >> N;
    vector<ll> A(60);
    long long num;
    rep(i, 0, N){
        cin >> num;
        rep(j, 0, 60){
            if ((num>>j)&1){
                A[j]++;
            }
        }
    }
    ll ans = 0, base = 1;
    rep(i, 0, 60){
        ll add = (N - A[i]) * A[i] % MOD * base % MOD;
        ans = (ans + add) % MOD;
        base = (2 * base) % MOD;
    }
    cout << ans << endl;
}