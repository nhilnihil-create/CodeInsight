#include <bits/stdc++.h>

#define F first
#define S second
#define int long long
#define inf 1000000000

using namespace std;

vector<vector<int> > dp;
vector<vector<bool> > v, used;

int getmn(int i, int j){
    if (i == 0 && j == 0){
        return 0;
    } else if (i == 0){
        return dp[i][j-1];
    } else if (j == 0){
        return dp[i-1][j];
    } else {
        return min(dp[i][j-1], dp[i-1][j]);
    }
    return 0;
}

void getdp(int i, int j, const int& di, const int& dj){
    dp[di][dj] = min(dp[di][dj], getmn(i, j)+1);
    if (i != 0 && !v[i-1][j] && !used[i-1][j]){
        used[i-1][j] = true;
        getdp(i-1, j, di, dj);
    }
    if (j != 0 && !v[i][j-1] && !used[i][j-1]){
        used[i][j-1] = true;
        getdp(i, j-1, di, dj);
    }
}

signed main(){
    int n, m;
    cin >> n >> m;
    dp.assign(n, vector<int>(m, inf));
    v.assign(n, vector<bool>(m, false));
    for (int i = 0; i < n; i++){
        for (int j = 0; j < m; j++){
            char c;
            cin >> c;
            if (c == '.'){
                v[i][j] = true;
            }
        }
    }
    for (int i = 0; i < n; i++){
        for (int j = 0; j < m; j++){
            if (v[i][j]){
                dp[i][j] = getmn(i, j);
            } else {
                used.assign(i+1, vector<bool>(j+1, false));
                used[i][j] = true;
                getdp(i, j, i, j);
            }
        }
    }
    cout << dp[n-1][m-1] << endl;
    return 0;
}





















