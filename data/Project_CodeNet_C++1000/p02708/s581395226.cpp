#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int INF = 1001001001;
const int MOD = 1000000007;
const double PI=acos(-1);

int main(){
    ll N,K;
    cin >> N >> K;

    ll ans = 0;

    for (ll k=K; k<=N+1; k++) {
        ans += (N+(N-k+1))*k/2 - (k-1)*k/2 + 1;
        ans %= MOD;
    }
    cout << ans << endl;
}
