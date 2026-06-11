#include <bits/stdc++.h>

#define rep(X,N) for(ll X = 0LL; X < (N); X++)
#define ALL(V) (V).begin(),(V).end()
#define endl "\n"

using namespace std;
typedef long long ll;

const double PI = 3.1415926535897932384626;
const ll MODN = 1000000007;
const ll MODN2 = 998244353;
const double EPS = 1e-10;

int main(){

    int h,w;
    cin >> h >> w;

    vector<string> v(h);
    
    rep(i, h){
        cin >> v[i];
    }

    vector<vector<int>> dp(h, vector<int>(w, 10005));

    dp[0][0] = (v[0][0] == '#' ? 1 : 0);
    
    rep(i, h){
        rep(j, w){
            if(i != h - 1){
                if(v[i][j] == '.' && v[i + 1][j] == '#'){
                    dp[i + 1][j] = min(dp[i + 1][j], dp[i][j] + 1);
                }else{
                    dp[i + 1][j] = min(dp[i + 1][j], dp[i][j]);
                }
            }

            if(j != w - 1){
                if(v[i][j] == '.' && v[i][j + 1] == '#'){
                    dp[i][j + 1] = min(dp[i][j + 1], dp[i][j] + 1);
                }else{
                    dp[i][j + 1] = min(dp[i][j + 1], dp[i][j]);
                }
            }
        }
    }

    cout << dp[h - 1][w - 1] << endl;

    return 0;
}
