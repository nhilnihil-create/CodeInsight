#include <iostream>
#include <algorithm>
#include <utility>
using namespace std;
int dp[3000][3000];
pair<int, int> ab[3000];

int main(){
    int n, t;
    int a, b;
    pair<int, int> c;
    cin >> n >> t;
    for (int i = 0; i < n; i++){
        cin >> a >> b;
        c = make_pair(a, b);
        ab[i] = c;
    }
    sort(ab, ab + n);
    for (int m = 1; m < n; m++){
        c = ab[m-1];
        a = c.first; b = c.second;
        for (int s = 1; s < t; s++){
            if (s < a) dp[m][s] = dp[m-1][s];
            else dp[m][s] = max(dp[m-1][s], dp[m-1][s-a] + b);
        }
    }
    int ans = 0;
    int happiness;
    for (int i = 0; i < n; i++){
        happiness = ab[i].second + dp[i][t-1];
        if (happiness > ans) ans = happiness;
    }
    cout << ans << '\n';

}
