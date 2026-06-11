#include <iostream>
#include <cstdio>
#include <vector>
using namespace std;

int main(){
    long long h, n;
    cin >> h >> n;

    vector<long long> a(n);
    vector<long long> b(n);

    for(long long i = 0; i < n; i++) cin >> a[i] >> b[i];

    vector<long long> dp(h+1, 1e12);
    dp[0] = 0;

    for(long long i = 1; i <= h; i++){
        for(long long j = 0; j < n; j++){
            if(i <= a[j]){
                dp[i] = min(dp[i], b[j]);
            }
            else{
                dp[i] = min(dp[i], dp[i-a[j]] + b[j]);
            }
        }
    }

    cout << dp[h] << endl;
    return 0;
}