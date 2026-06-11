#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;
int h, w;
vector<string> s(100);
    
int main(){
    cin >> h >> w;
    rep(i,h) cin >> s[i];
    int DP[h][w];
    if (s[0][0]=='.') DP[0][0] = 0;
    else DP[0][0] = 1;
    rep(i,h){
        rep(j,w){
            if (i==0 && j==0){
                continue;
            } else if (i==0){
                DP[i][j] = DP[i][j-1] + ((s[i][j]!=s[i][j-1]) ? 1 : 0);
            } else if (j==0){
                DP[i][j] = DP[i-1][j] + ((s[i][j]!=s[i-1][j]) ? 1 : 0);
            } else{
                DP[i][j] = min(DP[i][j-1]+(s[i][j]!=s[i][j-1] ? 1 : 0), 
                               DP[i-1][j]+((s[i][j]!=s[i-1][j]) ? 1 : 0));
            }
        }
    }

    int ans;
    ans = ceil(double(DP[h-1][w-1]) / 2);
    cout << ans << endl;
    return 0;
}