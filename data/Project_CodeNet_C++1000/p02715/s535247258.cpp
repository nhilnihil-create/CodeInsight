#include <bits/stdc++.h>
using namespace std;

#define MAX_K 100001
static const long M = 1000000007;

long N, K, G[MAX_K], ans = 0;

long power(long n, long m){
    long res = 1;
    if (m > 0){
        res = power(n, m / 2);
        if (m % 2 == 0) res = (res * res) % M;
        else res = (((res * res) % M) * n) % M;
    }
    return res;
}

void solve(){
    for(long i = K; i > 0; i--){
        G[i] = power(K / i, N);
        long a = 2;
        while(i * a <= K){
            G[i] -= G[i * a];
            a++;
        }
    }
    for(int i = 1; i <= K; i++){
        ans = (ans + i * G[i]) % M;
    }
    cout << ans << endl;
    return;
}

int main(){
    cin >> N >> K;
    solve();
    return 0;
}