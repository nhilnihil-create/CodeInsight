#include <iostream>
#include <vector>
#include <limits>
#include <map>
#define MOD 1000000007
#include <algorithm>
#include <math.h>
#include <utility>

using namespace std;
    long long int dp[305][305][305];

int main(){
    int n,k;
    cin >> n >> k;
    n++;

    vector<int> h(n);
    h[0] = 0;
    for(int i = 1; n - 1 >= i;i++){
        cin >> h[i];
    }

    for(int i = 0; n + 1 > i; i++)
        for(int j = 0; n + 1 + 1> j; j++)
            for(int l = 0; k + 1 > l; l++) dp[i][j][l] = 100000000000000LL;
    
    dp[0][0][k] = 0;

    for(int i = 0; n - 1> i; i++){
        for(int j = 0; i >= j; j++){
            for(int l = 0; k >= l; l++){
                if(dp[i][j][l] == 100000000000000LL) continue;
                dp[i + 1][i + 1][l] = min(dp[i + 1][i + 1][l], dp[i][j][l] + max(0, h[i + 1] - h[j]));
                if(l)
                    dp[i + 1][j][l-1] = min(dp[i + 1][j][l - 1], dp[i][j][l]);
            }
        }
    }

    long long int ans = 100000000000000LL;
        for(int j = 0; n > j; j++){
            for(int l = 0; k >= l; l++){
                ans = min(ans, dp[n-1][j][l]);
            }
        }
        cout << ans << endl;
    return 0;
}