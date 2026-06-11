#include <bits/stdc++.h>
using namespace std;
#define int long long
typedef pair<int,int> P;
int INF = 1e9+7;
int mod = 1e9+7;
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};
int mod_pow(int x,int y) {
    int res = 1;
    while(y > 0) {
        if(y%2) {
            res = res*x%mod;
        }
        x = x*x%mod;
        y/=2;
    }
    return res;
}
signed main(){
    int N,K;
    cin >> N >> K;
    vector<int>cnt(K+1);
    int res = 0;
    for(int i = K; i >= 2; i--) {
        cnt[i] += mod_pow(K/i,N);
        cnt[i] %= mod;
        for(int j = 2; j*j <= i; j++) {
            if(i%j == 0) {
                if(j*j != i) {
                    cnt[j] = (cnt[j]+mod-cnt[i])%mod;
                    cnt[i/j] = (cnt[i/j]+mod-cnt[i])%mod;
                }
                else {
                    cnt[j] = (cnt[j]+mod-cnt[i])%mod;
                }
            }
        }
        res += cnt[i];
    }
    int ans = (mod_pow(K,N)+mod-res)%mod;
    for(int i = 2; i <= K; i++) {
        ans += cnt[i]*i;
        ans %= mod;
    }
    cout << ans << endl;
}