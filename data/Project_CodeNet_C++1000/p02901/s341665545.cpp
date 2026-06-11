#include <bits/stdc++.h>
using namespace std;
const int INF = 1001001001;

template<class T> inline bool chmin(T& a, T b){if(a > b){ a = b; return true;} return false;}

int dp[1005][5000];

int main(){ //(以下https://drken1215.hatenablog.com/entry/2019/09/29/103500を参照)
    int n, m; cin >> n >> m;
    vector<int> a(m), b(m), c(m, 0);
    for(int i = 0; i < m; i++){
        cin >> a[i] >> b[i];
        for(int j = 0; j < b[i]; j++){
            int t; cin >> t;
            t--;
            c[i] += (1 << t);
        }
    }
    for(int i = 0; i < 1005; i++){
        for(int j = 0; j < 5000; j++){
            dp[i][j] = INF;
        }
    }
    dp[0][0] = 0;
    for(int i = 0; i < m; i++){
        for(int j = 0; j < (1<<n); j++){
            chmin(dp[i+1][j], dp[i][j]);
            int nj = j|c[i];
            chmin(dp[i][nj], dp[i][j] + a[i]);
        }
    }
    cout << (dp[m][(1<<n)-1] < INF ? dp[m][(1<<n)-1] : -1) << endl;
}