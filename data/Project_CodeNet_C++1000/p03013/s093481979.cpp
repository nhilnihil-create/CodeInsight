#include <bits/stdc++.h>

#define REP(i, n) for (int i = 0; i < (n); ++i)
#define RREP(i, n) for (int i = (n); i >= 0; --i)
#define FOR(i, a, b) for (int i = (a); i < (b); ++i)
#define RFOR(i, a, b) for (int i = (a); i >= (b); --i)
#define ALL(v) (v).begin(), (v).end()
#define RALL(a) (a).rbegin(), (a).rend()

#define uint8_t unsigned char
#define uint16_t unsigned short
#define uint32_t unsigned int
#define uint64_t unsigned long long

#define int8_t signed char
#define int16_t signed short
#define int32_t signed int
#define int64_t signed long long

using namespace std;

int main(int argc, char const* argv[])
{
    int N = 0;
    int M = 0;
    cin >> N >> M;

    vector<int> broken(N+1);
    REP(i,M) {
        int a;
        cin >> a;
        broken[a] = 1;
    }


    long long dp[N+1] = {};
    //REP(i, N) dp[i][j] = INT_MIN;

    dp[0] = 1;
    dp[1] = broken[1] ? 0:1;
    for (int i = 0; i <= N-2; i++) {

        dp[i+2] = (dp[i] + dp[i+1]) % 1000000007;
        if (broken[i+2]) {
            dp[i+2] = 0;
            continue;
        }        
    }

    cout << dp[N] << endl;

    return 0;
}


