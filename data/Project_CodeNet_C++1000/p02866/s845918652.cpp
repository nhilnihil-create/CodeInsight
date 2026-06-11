#include <bits/stdc++.h>
#define _GLIBCXX_DEBUG
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using namespace std;

long modpow(int a, int b, int mod){
    long tmp = 1;
    rep(i, b) {
        tmp *= a;
        tmp %= mod;
    } 
    return tmp;
}

int main(){
    int N;
    cin >> N;
    int mod=998244353;
    vector<int> D(N);
    for(auto &x: D){
        cin >> x;
    }

    int max = *max_element(D.begin(), D.end());
    vector<int> cnt(max+1);
    for (auto d:D){
        cnt[d]++;
    }

    if (D[0] != 0 || cnt[0] != 1){
        cout << 0 << endl;
        return 0;
    }

    long ans = 1;
    rep(i, max+1) {
        if(i == 0) continue;
        ans *= modpow(cnt[i-1], cnt[i], mod);
        ans %= mod;
    }
    cout << ans << endl;
}
