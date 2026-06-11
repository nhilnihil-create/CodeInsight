#include <bits/stdc++.h>

using namespace std;
using ll = long long int;
using P = pair<int, int>;

#define loop(i, n) for(int i = 0;i < n;i++)
#define IINF 2e9
#define MOD 1e9+7

int main(void){

    int h, w;
    cin >> h >> w;
    vector<string> fi(h);
    loop(i, h) cin >> fi[i];

    vector<vector<int>> dp(h, vector<int>(w, IINF));

    if(fi[0][0] == '#') dp[0][0] = 1;
    else dp[0][0] = 0;

    int dx[2] = {0, 1};
    int dy[2] = {1, 0};


    loop(i, h){
        loop(j, w){
            loop(k, 2){
                int nx = j + dx[k];
                int ny = i + dy[k];
                if(w <= nx || h <= ny) continue;
                if(fi[i][j] == '.' && fi[ny][nx] == '#'){
                    dp[ny][nx] = min(dp[ny][nx], dp[i][j] + 1);
                }else{
                    dp[ny][nx] = min(dp[ny][nx], dp[i][j]);
                }
            }
        }
    }


    cout << dp[h-1][w-1] << endl;

    return 0;
}