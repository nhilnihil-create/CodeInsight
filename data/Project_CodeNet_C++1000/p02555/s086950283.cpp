// 問題の URL を書いておく
// 

#include <algorithm>
#include <array>
#include <bitset>
#include <cmath>
#include <iostream>
#include <list>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <vector>

using namespace std;

//#define ENABLE_PRINT

#if defined(ENABLE_PRINT)

#define Print(v) \
do {\
    cout << #v << ": " << v << endl; \
}while(0)

#define PrintVec(v) \
do {\
    for(int __i = 0; __i < v.size(); ++__i) \
    { \
        cout << #v << "[" << __i << "]: " << v[__i] << endl; \
    }\
}while(0)

#else

#define Print(v) ((void)0)
#define PrintVec(v) ((void)0)

#endif

#define rep(i, n) for(int i = 0; i < (int)(n); ++i)

using ll = int64_t;

const ll M = 1000000000 + 7;

ll dp[2010] = {0};
ll sum[2010] = {0};

int main(int, const char**)
{
    int s;
    cin >> s;
    for(int i = 0; i <= s - 3; ++i)
    {
        dp[i + 3] = (sum[i] + 1) % M;
        sum[i + 3] = (sum[i + 2] + dp[i + 3]) % M;
    }
    cout << dp[s] << endl;
    return 0;
}
