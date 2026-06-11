#include<iostream>
#include<string.h>
#include<vector>
#include<list>
#include<stdio.h>
#include<math.h>
#include<iomanip>
#include<map>
#include<stack>
#include<queue>
#define range(i,a,b) for(int i = (a); i < (b); i++)
#define rep(i,b) range(i,0,b)
#define debug(x) cout << "debug " << x << endl;
using namespace std;

int dp[15][15];

int main(){
    int n;
    while(cin >> n, n){
        rep(i,15){
            rep(j,15){
                dp[i][j] = 2 << 24;
            }
            dp[i][i] = 0;
        }
        int ma = 0;
        rep(i,n){
            int a, b, c;
            cin >> a >> b >> c;
            dp[a][b] = c;
            dp[b][a] = c;
            if(ma < a)
                ma = a;
            if(ma < b)
                ma = b;
        }
        rep(k,n + 1){
            rep(i,n + 1){
                rep(j,n + 1){
                    dp[i][j] = min(dp[i][j], dp[i][k] + dp[k][j]);
                }
            }
        }
        int ans, time, mintime = 2 << 24;
        rep(i,ma + 1){
            time = 0;
            rep(j,ma + 1){
                time+= dp[i][j];
            }
            if(mintime > time){
                mintime = time;
                ans = i;
            }
        }
        cout << ans << ' ' << mintime << endl;
    }
}