#include<bits/stdc++.h>

int main(){
    using namespace std;
    unsigned long N, K;
    cin >> N >> K;
    if(N == K)return 0 & puts("0");
    vector<unsigned long> H;
    H.reserve(N + 2);
    H.push_back(0);
    copy_n(istream_iterator<unsigned long>(cin), N, back_inserter(H));
    H.push_back(0);
    unsigned long ans{0};
    for(unsigned long i = 0; i < N; ++i)ans += max(H[i + 1], H[i]) - H[i];
    vector<vector<unsigned long>> table(K + 1);
    table[0].resize(N);
    for(unsigned long i = 1; i <= K; ++i){
        table[i].resize(N - i + 1);
        for(unsigned long j = 0; j + i <= N; ++j){
            for(unsigned long k = 0; k <= i; ++k){
                table[i][j] += max(H[j + k + 1], H[j + k]) - min(H[j + k + 1], H[j + k]);
            }
            table[i][j] -= max(H[j], H[i + j + 1]) - min(H[j], H[i + j + 1]);
            table[i][j] /= 2;
        }
    }
    vector<vector<unsigned long>> dp(K + 1);
    vector<unsigned long> dpp(K + 1);
    for(unsigned long i = 0; i <= K; ++i)dp[i].resize(i + 1);
    for(unsigned long i = 0; i < N; ++i){
        for(unsigned long j = min(K, i + 1) + 1; j--; ){
            dp[j][0] = dpp[j];
            for(unsigned long k = 1; k <= j; ++k){
                dpp[j] = max(dpp[j], dp[j][k] = dp[j - 1][k - 1] + table[k][i - k + 1] - table[k - 1][i - k + 1]);
            }
        }
    }
    cout << ans - dpp.back() << endl;
    return 0;
}