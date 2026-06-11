#include"bits/stdc++.h"
#include<unordered_set>
#include<unordered_map>
#include<random>
using namespace std;
typedef long long ll;
const ll MOD = (ll)(1e9+7);
#define pb push_back
#define mp make_pair
#define all(x) (x).begin(), (x).end()
#define rep(i, n) for(int (i)=0; (i)<(n); (i)++)
int dx[4]={ 1,0,-1,0 };
int dy[4]={ 0,1,0,-1 };

int H, W;
string S[100];

int dp[100][100][2];
int solve(int y, int x, bool c){
    if(y >= H || x >= W) return 1e9;
    if(y == H-1 && x == W-1){
        if(!c && S[y][x] == '#') return 1;
        return 0;
    }
    if(dp[y][x][c] != -1) return dp[y][x][c];
    
    int ret;
    if(!c && S[y][x] == '#'){
        ret = min(solve(y+1, x, !c), solve(y, x+1, !c)) + 1;
    }
    else if(c && S[y][x] == '.'){
        ret = min(solve(y+1, x, !c), solve(y, x+1, !c));
    }
    else{
        ret = min(solve(y+1, x, c), solve(y, x+1, c));
    }
    return dp[y][x][c] = ret;
}

signed main(){
    cin >> H >> W;
    rep(i, H) cin >> S[i];
    memset(dp, -1, sizeof(dp));
    cout << solve(0, 0, 0) << endl;
}