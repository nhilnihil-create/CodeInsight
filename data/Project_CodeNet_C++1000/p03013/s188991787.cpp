#include <bits/stdc++.h>
using namespace std;
#define PI 3.141592653589793
#define MOD 1000000007
typedef long long ll;
typedef long double ld;

int main() {
    ll  N, M;
    cin >> N >> M;
    vector<ll> a(M, 0);
    for(int i = 0; i < M; i++) cin >> a[i];
    ll ans = 0;
    ll dp[N + 1] = {0};

    for(int i = 0; i < M; i++){
        dp[a[i]] = -1;

        if(a[i] + 1 == a[i + 1]){
            cout << 0 << endl;
            return 0;
        }

    }

    if(dp[0] == 0){
        dp[0] = 1;
    }
    else{
        dp[1] = 1;
    }

    for(int i = 0; i < N; i++){
        ll tmp1, tmp2;
        if(dp[i + 1] == -1) continue;

        if(dp[i] == -1){
            tmp1 = 0;
        }
        else{
            tmp1 = dp[i];
        }

        if(i == 0 || dp[i - 1] == -1){
            tmp2 = 0;
        }
        else{
            tmp2 = dp[i - 1];
        }
        dp[i + 1] = (tmp1 + tmp2) % MOD;

    }

    cout << dp[N] << endl;

}
