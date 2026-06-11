#include <iostream>
#include <vector>
#include <map>
using namespace std;
int main(){
    int N;
    long long K;
    cin >> N >> K;
    vector<long long> A(N);
    for(int i = 0; i < N; i++) cin >> A[i];
    vector<long long> sum(N + 1, 0);
    for(int i = 0; i < N; i++){
        sum[i + 1] = (sum[i] + A[i]) % K;
    }
    for(int i = 0; i < N + 1; i++){
        sum[i] = (sum[i] - i % K + K) % K;
    }
    map<long long, long long> m;
    if(K > N){
        for(int i = 0; i < N + 1; i++){
            m[sum[i]]++;
        }
        long long ans = 0;
        for(auto v: m){
            ans += (v.second * (v.second - 1)) / 2;
        }
        cout << ans << endl;
        return 0;
    }
    long long ans = 0;
    for(int i = 0; i < K; i++){
        m[sum[i]]++;
    }
    for(auto v: m){
        ans += (v.second * (v.second - 1)) / 2;
    }
    for(int i = K; i < N + 1; i++){
        m[sum[i - K]]--;
        ans += m[sum[i]];
        m[sum[i]]++;
    }
    cout << ans << endl;
}