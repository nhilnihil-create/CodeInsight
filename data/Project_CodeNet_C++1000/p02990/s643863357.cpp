#include <bits/stdc++.h>

using namespace std;

// xのn乗のmodでのmodを返す

long long int modpow(long long int x,long long int n,long long int mod){
    long long int res = 1;
    while(n>0){
        if(n&1){
            res = (res*x)%mod;
        }
        x = (x*x)%mod;
        n >>= 1;
    }
    return res;
}

long long int COM(long long int N, long long int R, long long int MOD){
    long long int ans = 1,div=1;
    for(long long int i=0;i<R;i++){
        ans *= N-i;
        div *= i+1;
        ans %= MOD;
        div %= MOD;
    }

    ans *= modpow(div,MOD-2,MOD);
    ans %= MOD;

    return ans;
}

long long int MOD = 1000000007;

int main(){
    long long int N,K;
    cin >> N >> K;
    for(long long int i=1;i<=K;i++){
        cout << COM(N-K+1,i,MOD)*COM(K-1,i-1,MOD)%MOD << endl;
    }
}