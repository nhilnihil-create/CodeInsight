#include <iostream>
#include <cstring>
#include <cmath>
#include <vector>
#include <algorithm>
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <set>
#include <map>
#include <iterator>
#include <stack>
#include <string.h>
#include <cstdlib>
#include <queue>
#include <list>
#include <string>

using namespace std;

int h,w;
char f[105][105];

int main()
{
    cin >> h >> w;
    for (int i = 1;i <= h;i++){
        for (int j = 1;j <= w;j++){
            cin >> f[i][j];
        }
    }
    
    int dp[105][105];
    
    for (int i = 1;i <= h;i++){
        for (int j = 1;j <= w;j++){
            if (i == 1 && j == 1){
                if (f[i][j] == '#'){
                    dp[i][j] = 1;
                }
                else {
                    dp[i][j] = 0;
                }
            }
            else if (i == 1 && j != 1){
                if (f[i][j] == '#' && f[i][j-1] == '.'){
                    dp[i][j] = dp[i][j-1] + 1;
                }
                else {
                    dp[i][j] = dp[i][j-1];
                }
            }
            else if (i != 1 && j == 1){
                if (f[i][j] == '#' && f[i-1][j] == '.'){
                    dp[i][j] = dp[i-1][j] + 1;
                }
                else {
                    dp[i][j] = dp[i-1][j];
                }
            }
            else {
                int k = dp[i-1][j];
                int l = dp[i][j-1];
                if (f[i][j] == '#' && f[i-1][j] == '.'){
                    k += 1;
                }
                if (f[i][j] == '#' && f[i][j-1] == '.'){
                    l += 1;
                }
                
                dp[i][j] = min(k,l);
            }
        }
    }
    cout << dp[h][w] << endl;
}
