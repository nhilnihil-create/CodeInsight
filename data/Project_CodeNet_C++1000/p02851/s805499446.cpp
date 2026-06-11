#include <bits/stdc++.h>
using namespace std;
using ll  = long long;
using vl  = vector<ll>;
using vvl = vector<vl>;

#define rep(i,n) for(int i = 0; i < (n); ++i)
#define per(i,n) for(int i = (n)-1; i >= 0; --i)
#define rng(i,a,b) for(int i = (a); i < (b); ++i)
#define all(a) (a).begin(), (a).end()

int main() {
    int N, K;
    cin >> N >> K;
    vl A(N);
    rep(i,N) {
        cin >> A[i];
        A[i]--;
    }

    map<ll, ll> cnts;
    cnts[0] = 1;
    ll ans = 0, sum_mod = 0;
    vl sum_mods(1,0);
    rep(i,N) {
        (sum_mod += A[i]) %= K;
        sum_mods.push_back(sum_mod);
        if (i >= K-1) cnts[sum_mods[i-(K-1)]]--;
        ans += cnts[sum_mod];
        cnts[sum_mod]++;
    } cerr << endl;
    cout << ans << endl;
    return 0;
}
