#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
#include <cmath>

using namespace std;

const long MOD = 1000000007;
typedef pair<int, int> P;
typedef long long ll;

const int MAX_N = 12;
const int MAX_M = 1000;
int N, M;
int c[MAX_M][MAX_N];
int a[MAX_M], b[MAX_M];

int main(){
    cin >> N >> M;

    for(int i=0; i<M; i++){
        cin >> a[i] >> b[i];
        for(int j=0; j<b[i]; j++){
            cin >> c[i][j];
            c[i][j]--;
        }
    }

    int num = pow(2, N);
    int dp[M+1][num];
    for(int i=0; i<=M; i++){
        for(int j=0; j<num; j++) dp[i][j] = 1000000005;
    }

    dp[0][0] = 0;

    for(int i=0; i<M; i++){
        // cout << "------ " << i << endl;
        for(int j=0; j<num; j++){
            dp[i+1][j] = min(dp[i+1][j], dp[i][j]);

            int t = 0;
            for(int k=0; k<b[i]; k++){
                t |= 1 << c[i][k];
            }
            // cout << "====" << endl;
            // cout << j << " " << t << endl;
            dp[i+1][j|t] = min(dp[i][j]+a[i], dp[i+1][j|t]);
            // cout << dp[i][j] << " " << dp[i+1][j|t] << endl;
        }
    }

    if(dp[M][num-1] == 1000000005) cout << -1 << endl;
    else cout << dp[M][num-1] << endl;

    return 0;
}
