#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>
#include <cmath>
#include <map>

#define reps(i,s,n) for(int (i) = (s); (i) < (n); (i)++)
#define rep(i,n) reps(i,0,n)
using namespace std;
using ll = long long;
using vi = vector<int>;

int main(){
    int h,n;
    cin >> h >> n;
    const int INF = 1e9;
    vi dp(10100,INF);

    int a,b;
    dp[0] = 0;
    rep(i,n){
        cin >> a >> b;
        rep(j,10100){
            // if(j-a>=0){
            //     dp[j] = min(dp[j-a]+b,dp[j]);
            // }
            
                dp[j] = min(dp[max(j-a,0)]+b,dp[j]);
        }
    }

    // rep(i,h){
    //     cout << i << " " << dp[i] << endl;
    // }

    cout << dp[h] << endl;
    return 0;
}