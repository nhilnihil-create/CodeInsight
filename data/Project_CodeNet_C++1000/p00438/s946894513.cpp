#include <iostream>
using namespace std;

int dp[17][17];
int road[17][17];

int main()
{
    int a, b;
    int n;
    while(cin >> a >> b && a && b) {

        for(int i = 0; i <= b; i++) 
            for(int j = 0; j <= a; j++) 
                dp[i][j] = road[i][j] = 0;

        cin >> n;
        int x, y;
        for(int i = 0; i < n; i++) {
            cin >> x >> y;
            road[y][x] = 1;
        }
        
        for(int i = 1; i <= b; i++) {
            for(int j = 1; j <= a; j++) {
                if(i == 1 && j == 1) {
                    dp[i][j] = 1;
                } else {
                    dp[i][j] = (road[i][j]) ? 0 : dp[i-1][j] + dp[i][j-1];
                }
            }
        }

        cout << dp[b][a] << endl;

    }
}