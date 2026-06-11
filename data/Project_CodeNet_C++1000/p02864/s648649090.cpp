#include <iostream>
#include <vector>
#include <map>
#include <unordered_map>
#include <queue>
#include <set>
#include <algorithm>
#include <string>
#include <math.h>
#include <limits.h>
#include <stack>
#include <complex>
#include <stdlib.h>
#include <stdio.h>
#include <functional>
#include <cfloat>
#include <math.h>
#include <numeric>
#include <string.h>
#include <sys/time.h>
#include <random>


#define fs first
#define sc second

using namespace std;

typedef long long ll;
typedef pair<int, int> P;

ll dp[310][310][310];
ll h[310];
ll INF = LONG_LONG_MAX / 500;
int main(){
    int N, K;
    cin >> N >> K;
    h[0] = 0;
    for(int i = 0; i < N; i++){
        cin >> h[i+1];
    }
    for(int i = 0; i < 310; i++){
        for(int j = 0; j < 310; j++){
            for(int k = 0; k < 310; k++) {
                dp[i][j][k] = INF;
            }
        }
    }
    for(int j = 0; j < 310; j++){
        dp[0][j][0] = 0;

    }
    for(int i = 0; i < N; i++){
        for(int j = 0; j <= K; j++){
            for(int k = 0; k <= i; k++){
                // 値を変更する
                dp[i+1][j+1][k] = min(dp[i+1][j+1][k], dp[i][j][k]);
                // 値を変更しない
                dp[i+1][j][i+1] = min(dp[i+1][j][i+1], dp[i][j][k] + max(0LL, h[i+1] - h[k]));
            }
        }
    }

    ll res = INF;
    for(int j = 0; j <= K; j++){
        for(int k = 0; k <= N; k++){
            res = min(dp[N][j][k], res);
        }
    }

    cout << res << endl;



    return 0;
}


