#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <map>
#include <cmath>
#include <set>
#include <algorithm>
#include <iomanip>

typedef long long ll;
const ll MOD = 1e9 + 7;
const long long INF = 1LL<<60;
const double PI=3.14159265358979323846;
const int NMAX=100005;
using namespace std;



int main(){
    int h,n;
    cin >> h >> n;
    vector<pair<int, int>> m(n);
    for(int i = 0; i < n; i++){
        cin >> m[i].first >> m[i].second;
    }

    int dp[h+1];
    for(int i = 0; i <= h; i++){
        dp[i] = 999999999;
    }
    dp[0] = 0;
    for(int i = 0; i < h; i++){
        for(int j = 0; j < n; j++){
            int tg = i+m[j].first;
            if(tg > h) tg = h;
            dp[tg] = min(dp[tg], dp[i]+m[j].second);
        }
    }

    cout << dp[h] << endl;

    return 0;
}