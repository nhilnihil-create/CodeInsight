#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <string>
#include <iomanip>
#include <math.h>
#include <utility>
#include <vector>
#include <map>
#include <unordered_map>
#include <cstdlib>
#include <stack>
#include <queue>
#define div1 1000000007
const long long INF = 1LL << 60;
using namespace std;
using ll = long long;
using ld = long double;
// a>b -> a==b;
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }
// a<b -> a==b;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }

int main(void)
{
    ll H, W, i, j, dp[110][110];
    string s[110];

    cin >> H >> W;

    for(i=0; i<H; i++){
        for(j=0; j<W; j++){
            dp[i][j] = INF;
        }
    }

    for(i=0; i<H; i++){
        cin >> s[i];
    }

    if(s[0][0]=='#'){
        dp[0][0] = 1;
    }
    else{
        dp[0][0] = 0;
    }

    for(i=0; i<H; i++){
        for(j=0; j<W; j++){
            if(i<H-1){
                if(s[i][j]=='.' && s[i+1][j]=='#'){
                    chmin(dp[i+1][j], dp[i][j]+1);
                }
                else chmin(dp[i+1][j], dp[i][j]);
            }

            if(j<W-1){
                if(s[i][j]=='.' && s[i][j+1]=='#'){
                    chmin(dp[i][j+1], dp[i][j]+1);
                }
                else chmin(dp[i][j+1], dp[i][j]);
            }
        }
    }

    cout << dp[H-1][W-1] << endl;

    return 0;
}