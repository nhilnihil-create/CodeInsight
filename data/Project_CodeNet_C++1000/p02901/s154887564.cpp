#include<iostream>
#include<vector>
#include<algorithm>
#include<cstring>
using namespace std;

const int N_MAX = 12;
const int S_MAX = 1 << N_MAX;
const int M_MAX = 1000;
const int INF = 100000005;

int dp[M_MAX + 5][S_MAX + 5];

int main(){
    int n, m;
    cin >> n >> m;
    int a[M_MAX+3], b[M_MAX+3];
    int c[M_MAX+3][N_MAX+3];
    int Sc[M_MAX+3];
    memset(Sc, 0, sizeof(Sc));
    for(int i = 0; i < m; i++){
        cin >> a[i] >> b[i];
        for(int j = 0; j < b[i]; j++){
            cin >> c[i][j];
            c[i][j]--;
            Sc[i] |= (1 << c[i][j]);
        }
    }

    for(int i = 0; i <= m; i++){
        for(int S = 0; S != 1 << n; S++)dp[i][S] = INF;
    }

    dp[0][0] = 0;
    for(int i = 0; i < m; i++){
        for(int S = 0; S != 1 << n; S++){
            dp[i+1][S] = min(dp[i+1][S], dp[i][S]);
            dp[i+1][S|Sc[i]] = min(dp[i+1][S|Sc[i]], dp[i][S]+a[i]);
        }
    }
    int ans;
    if (dp[m][(1 << n)-1] < INF)ans = dp[m][(1 << n)-1];
    else ans = -1;
    cout << ans << endl;
    return 0;
}