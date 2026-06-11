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

string L;

Int dp[100000+10][2];

int main(void) {
    cin>>L;

    dp[0][0] = 1;
    for(int i = 0;i < L.size();i++) {
        if(L[i] == '1') {
            //a+b == 0
            dp[i+1][1] += (dp[i][0]+dp[i][1])%MOD;
            //a+b == 1
            dp[i+1][0] += dp[i][0]*2%MOD;
            dp[i+1][1] += dp[i][1]*2%MOD;
        } else {
            //a+b == 0
            dp[i+1][1] += dp[i][1];
            dp[i+1][0] += dp[i][0];
            //a+b == 1
            dp[i+1][1] +=dp[i][1]*2%MOD;

        }
    }

    cout<<(dp[L.size()][0]+dp[L.size()][1])%MOD<<endl;

    return 0;
}
