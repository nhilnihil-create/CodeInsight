#include<bits/stdc++.h>
using namespace std;

using i64 = long long;
using u64 = unsigned long long;

const int mod = (int)1e9+7;

void __print() {cerr << "]\n";}

template<typename T, typename... V>
void __print(T t, V... v)
{ cerr << t; if(sizeof...(v)) cerr << ", "; __print(v...);}

#define dbg(x...) cerr << __LINE__ << " : [" << #x << "] = ["; __print(x)


int main()
{
    string s;
    cin >> s;
    int len = s.length();
    vector<i64> dp(13, 0);
    dp[0] = 1;
    for (int i = 0; i < len; i++) {
        vector<i64> new_dp(13, 0);
        if(s[i] == '?') {
            for(int j = 0; j < 10; j++) {
                for(int k = 0; k < 13; k++) {
                    new_dp[(k*10+j)%13] += dp[k];
                    new_dp[(k*10+j)%13] %= mod;
                }
            }
            dp = new_dp;
        } else {
            for(int k = 0; k < 13; k++) {
                new_dp[(k*10+s[i]-'0')%13] += dp[k];
                new_dp[(k*10+s[i]-'0')%13] %= mod;
            }
            dp = new_dp;
        }
    }
    printf("%lld\n", dp[5]);
}
