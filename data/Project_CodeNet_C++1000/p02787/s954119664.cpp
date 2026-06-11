#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>
#include <cmath>
#include <map>
#include <queue>
#include <string>

#define reps(i,s,n) for(int (i) = (s); (i) < (n); (i)++)
#define rep(i,n) reps(i,0,n)
using namespace std;
using ll = long long;
using pii = pair<int,int>;
using vi = vector<int> ;
using vl = vector<ll>;

const int INF = 1e9;

int dp[10010];
int main(){
    int h,n;
    cin >> h >> n;

    vi dmg(n),mp(n);
    rep(i,n){
        cin >> dmg[i] >> mp[i];
    }

    rep(j,10010){
        dp[j] = INF;
    }
    dp[0] = 0;

    rep(i,n){
        rep(j,10010){
            dp[j] = min(dp[j],dp[max(0,j-dmg[i])] + mp[i]);
        }
    }
    // rep(i,h+1){
    //     cout << dp[i] << " ";
    // }cout << endl;
    cout << dp[h] << endl;
    return 0;
}