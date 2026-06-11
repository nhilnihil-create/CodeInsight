#include<bits/stdc++.h>
using namespace std;
typedef pair<int ,int> P;
int inf = 100000000;

int main(){
    int h,w;
    cin >> h >> w;
    vector<vector<char>> vec(h ,vector<char>(w));
    for(int i=0;i<h;i++) for(int j=0;j<w;j++) cin >> vec[i][j];

    int dp[105][105];
    for(int i=0;i<h;i++) for(int j=0;j<w;j++) dp[i][j] = inf;
    if(vec[0][0] == '.') dp[0][0] = 0;
    else                dp[0][0] = 1;

    for(int i=1;i<h;i++) {
        if(vec[i-1][0]=='.' && vec[i][0]=='#') dp[i][0] = min(dp[i][0] ,dp[i-1][0] + 1);
        else                                   dp[i][0] = min(dp[i][0] ,dp[i-1][0]);
    }

    for(int j=1;j<w;j++){
        if(vec[0][j-1]=='.' && vec[0][j]=='#') dp[0][j] = min(dp[0][j] ,dp[0][j-1] + 1);
        else                                   dp[0][j] = min(dp[0][j] ,dp[0][j-1]);
    }


    for(int i=1;i<h;i++) for(int j=1;j<w;j++){
        if(vec[i][j-1]=='.' && vec[i][j]=='#') dp[i][j] = min(dp[i][j] ,dp[i][j-1] + 1);
        else                                   dp[i][j] = min(dp[i][j] ,dp[i][j-1]);
        if(vec[i-1][j]=='.' && vec[i][j]=='#') dp[i][j] = min(dp[i][j] ,dp[i-1][j] + 1);
        else                                   dp[i][j] = min(dp[i][j] ,dp[i-1][j]);
    }
    cout << dp[h-1][w-1] << endl;
}