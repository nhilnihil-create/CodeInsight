#include<iostream>
#include<iomanip>
#include<vector>
#include<string>
#include<cstring>
#include<map>
#include<set>
#include<queue>
#include<stack>
#include<algorithm>
#include<cmath>
#include<cstdio>
#include<cstdlib>
#include<climits>
#include<fstream>

#define MOD (1000000007)

using namespace std;

typedef long long int Int;

constexpr Int TEN(int n) { return n == 0 ? 1 : 10 * TEN(n-1); }

const int max_n = 100000+10;
Int dp[max_n][2]; //dp[digit][flag],flag=0or1 0: just, 1: smaller

int main(void) {
    string L;
    cin>>L;

    dp[0][0] = 1;
    for(int i = 0;i < L.size();i++) {
        if(L[i] == '1') {
            //a+b = 0
            dp[i+1][1] += (dp[i][0]+dp[i][1]);
            //a+b  = 1
            dp[i+1][0] += 2*dp[i][0];
            dp[i+1][1] += 2*dp[i][1];
        } else {
            //a+b = 0
            dp[i+1][0] += dp[i][0];
            dp[i+1][1] += dp[i][1];
            //a+b =1
            dp[i+1][1] += 2*dp[i][1];
        }
        dp[i+1][0] %= MOD;
        dp[i+1][1] %= MOD;
    }

    cout<<(dp[L.size()][0]+dp[L.size()][1])%MOD<<endl;


    return 0;
}
