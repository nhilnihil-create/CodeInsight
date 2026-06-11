#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <cstring>
#include <cctype>
#include <complex>
#include <stack>
#include <queue>
#include <unordered_map>
#include <set>
#include <deque>
#include <map>
#include <bitset>
#include <functional>
#include <cmath>

#define INF 1000000000
using namespace std;
const long MOD = 1000000007;

int main(){
    long long n, m;
    cin >> n >> m;
    vector<long long> a(n+1);

    long long i;
    for(i = 0; i <= n; i++){
        a[i] = 1;
    }

    for(i = 0; i < m; i++){
        long long p;
        cin >> p;
        a[p] = 0;
    }

    long long dp[n+2];
    for(i = 0; i < n+2; i++) dp[i] = 0;
    dp[0] = 1;
    if(a[1] == 0) dp[1] = 0;
    else dp[1] = 1;

    for(i = 2; i <= n; i++){
        if(a[i] == 0) continue;
        dp[i] += ((dp[i-1] + dp[i-2]) % MOD);
        dp[i] %= MOD;
    }

    cout << dp[n] << endl;
}