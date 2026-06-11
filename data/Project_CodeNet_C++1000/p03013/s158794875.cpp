#include <iostream>
#include <string>
#include <math.h>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
using namespace std;

typedef long long ll;
#define rep(i, n) for(int i = 0; i < n; i++)

int main(){
    int N, M;
    cin >> N >> M;
    vector<bool> is(N+1, true);
    vector<ll> dp(N+1, 0);
    rep(i, M){
        int a;
        cin >> a;
        is[a] = false;
    }

    int mod = pow(10, 9)+7;
    dp[0] = 1;
    rep(i, N){
        for(int j = i+1; j <= min(i+2, N); j++){
            if(is[j]){
                dp[j] = (dp[j] + dp[i]) % mod;
            }
        }
    }
    cout << dp[N] << endl;
    return 0;
}