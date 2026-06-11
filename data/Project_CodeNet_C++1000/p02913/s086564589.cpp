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

const int max_n = 5000+10;
int dp[max_n][max_n];

int main(void) {
    int N;
    cin>>N;
    string S;
    cin>>S;
    for(int i = 0;i < N;i++) {
        dp[i][i] = 1;
    }

    for(int i = N-1;i >= 0;i--) {
        for(int j = N-1;j >= 0;j--) {
            if(S[i] == S[j]) {
                dp[i][j] = dp[i+1][j+1] + 1;
            } else {
                dp[i][j] = 0;
            }
        }
    }

    int ans = 0;
    for(int i = 0;i < N;i++) {
        for(int j = 0;j < N;j++) {
            if(i >= j)
                continue;
            int now = min(dp[i][j],j-i);
            ans = max(ans,now);
        }
    }

    cout<<ans<<endl;

    return 0;
}
