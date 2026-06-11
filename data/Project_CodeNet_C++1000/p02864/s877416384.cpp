#include <algorithm>
#include <iostream>
#include <iomanip>
#include <cstring>
#include <string>
#include <vector>
#include <queue>
#include <cmath>
#include <stack>
#include <set>
#include <map>
typedef long long ll;
using namespace std;

const ll INF = 1LL << 50;

int main(){
    int N, K;
    cin >> N >> K;
    ll a[N + 1];
    a[0] = 0;
    for(int i = 0; i < N; i++) cin >> a[i + 1];

    //削除しない項のうち最も右がi, 削除しない項の集合のサイズがjのときのmin
    ll dp[N + 1][N + 1];
    fill(dp[0], dp[N + 1], INF);

    for(int i = 0; i <= N; i++){
        for(int j = 0; j <= N; j++){
            if(i == 0 && j == 0) dp[i][j] = 0;
            else if(j == 0) dp[i][j] = INF;
            else if(i < j) dp[i][j] = INF;
            else {
                //dp[i][j] = min(dp[0~i-1][j-1] + max(0, a[i] - a[x]));
                for(int k = 0; k < i; k++){
                    dp[i][j] = min(dp[i][j], dp[k][j - 1] + max(0LL, a[i] - a[k]));
                }
            }
        }
    }

    ll ans = INF;
    for(int i = 0; i <= N; i++){
        ans = min(ans, dp[i][N - K]);
    }

    //debug
    /*
    for(int i = 0; i <= N; i++){
        for(int j = 0; j < N; j++){
            cout << dp[i][j] << " ";
        }
        cout << endl;
    }*/

    cout << ans << endl;
    return 0;
}