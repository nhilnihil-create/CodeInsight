#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<ll,ll> P;
#define MOD 1000000007

ll N, K;

ll solve() {
    vector<ll> A (N + 1, 0);
    ll ans = 0;
    for (size_t i = 1; i < N + 1; i++) A.at(i) = A.at(i - 1) + i;
    for (size_t i = K; i < N + 1; i++) {
        ans += A.at(N) - A.at(N - i) - A.at(i - 1) + 1;
        ans %= MOD;
    }
    ans += 1;
    ans %= MOD;
    return ans;
}

int main(){
    cin >> N >> K;
    cout << solve() << endl;
    return 0;
}
