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

int N,M;

Int dp[2010][2010];
Int S[2010];
Int T[2010];

int main(void) {
    cin>>N>>M;
    for(int i = 1;i <= N;i++) {
        cin>>S[i];
    }
    for(int i = 1;i <= M;i++) {
        cin>>T[i];
    }

    for(int i = 0;i <= N;i++)
        dp[i][0] = 1;
    for(int j = 0;j <= M;j++)
        dp[0][j] = 1;

    for(int i = 1;i <= N;i++) {
        for(int j = 1;j <= M;j++) {
            if(S[i] == T[j]) {
                dp[i][j] = dp[i][j-1]+dp[i-1][j];
            } else {
                dp[i][j] = dp[i][j-1]+dp[i-1][j]-dp[i-1][j-1]+MOD;
            }

            dp[i][j] %= MOD;
        }
    }

    cout<<dp[N][M]<<endl;


    return 0;
}
