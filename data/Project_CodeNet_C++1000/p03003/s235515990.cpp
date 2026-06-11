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

const int max_n = 3000;
Int dp[max_n][max_n];

Int S[max_n];
Int T[max_n];

int main(void) {
    int N,M;
    cin>>N>>M;

    dp[0][0] = 1;
    for(int i = 1;i <= N;i++) {
        dp[i][0] = 1;
        cin>>S[i];
    }
    for(int i = 1;i <= M;i++) {
        dp[0][i] = 1;
        cin>>T[i];
    }

    for(int i = 1;i <= N;i++) {
        for(int j = 1;j <= M;j++) {
            if(S[i] == T[j]) {
                dp[i][j] = (dp[i-1][j]+dp[i][j-1])%MOD;
            } else {
                dp[i][j] = (MOD + dp[i-1][j]+dp[i][j-1]-dp[i-1][j-1])%MOD;
            }
        }
    }

    cout<<dp[N][M]<<endl;


    return 0;
}
