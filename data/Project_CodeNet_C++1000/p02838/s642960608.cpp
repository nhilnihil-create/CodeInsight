#include <iostream>
#include <vector>
using namespace std;
long long MOD = 1e9 + 7;
int main(){
    int N;
    cin >> N;
    vector<long long> A(N);
    for(int i = 0; i < N; i++) cin >> A[i];
    vector<long long> cnt(60, 0);
    for(int i = 0; i < N; i++){
        int cn = 0;
        long long t = A[i];
        while(t > 0){
            if(t % 2 == 1) cnt[cn]++;
            cn++;
            t >>= 1;
        }
    }
    long long ans = 0;
    for(int i = 0; i < N; i++){
        vector<int> c(60, 0);
        int cn = 0;
        while(A[i] > 0){
            if(A[i] % 2 == 1) c[cn]++;
            cn++;
            A[i] >>= 1;
        }
        for(int j = 0; j < 60; j++){
            if(c[j] == 1){
                cnt[j]--;
                ans += (1LL << j) % MOD * (N - i - 1 - cnt[j]) % MOD;
                ans %= MOD;
            }
            else{
                ans += (1LL << j) % MOD * cnt[j] % MOD;
                ans %= MOD;
            }
        }
    }
    cout << ans << endl;
}