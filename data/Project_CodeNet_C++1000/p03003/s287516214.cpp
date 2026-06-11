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
vector<int> S,T;
const int max_n = 2010;

Int dp[max_n][max_n];

int main(void) {
    cin>>N>>M;
    for(int i = 0;i < N;i++) {
        int s;
        cin>>s;
        S.push_back(s);
    }
    for(int i = 0;i < M;i++) {
        int t;
        cin>>t;
        T.push_back(t);
    }
    
    for(int i = 0;i <= N;i++) {
        dp[i][0] = 1;
    }
    for(int i = 0;i <= M;i++) {
        dp[0][i] = 1;
    }

    for(int i = 0;i < N;i++) {
        for(int j = 0;j < M;j++) {
            if(S[i] == T[j]) {
                dp[i+1][j+1] = dp[i+1][j]+dp[i][j+1];
            } else {
                dp[i+1][j+1] = dp[i+1][j]+dp[i][j+1]-dp[i][j]+MOD;
            }
            dp[i+1][j+1] %= MOD;
        }
    }

    cout<<dp[N][M]<<endl;


    return 0;
}

