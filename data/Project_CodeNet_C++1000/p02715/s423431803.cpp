#include <bits/stdc++.h>
#define int long long

#define mp make_pair
#define pb push_back

const int mod = (int)1e9+7;
using namespace std;

int fastp(int a, int b){
    int res = 1;
    a %= mod;
    while(b){
        if(b&1) res = (res * a) % mod;
        a *= a; a %= mod;
        b >>= 1;
    }
    return res%mod;
}
signed main(){
    int n,a;
    cin >> n >> a;
    int s = 0;
    int cnt[a];
    memset(cnt,0,sizeof cnt);
    for(int i = 1;i<=a;i++){
        int x = a/i;
        cnt[i-1] = fastp(x,n)%mod;
    }
    s = 0;
    for(int i = a;i>=1;i--){
        int cnn = cnt[i-1];
        cnn %= mod;
        for(int z = i+i;z <= a;z += i){
            cnn -= cnt[z-1];
            cnn += mod+mod;
            cnn %= mod;
        }
        cnt[i-1] = cnn;
        cnt[i-1] += mod;
        cnt[i-1] %= mod;
        s += cnn*(i)%mod;
        s %= mod;
    }
    cout << s;
}
