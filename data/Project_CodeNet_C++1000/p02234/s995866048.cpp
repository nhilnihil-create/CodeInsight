#include <iostream>
#include <list>
#include <vector>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <numeric>
#include <algorithm>
#include <cmath>
#include <string>
using namespace std;
typedef long long lli;
typedef vector<lli> vll;
typedef vector<bool> vbl;
typedef vector<vector<lli> > mat;
typedef vector<vector<bool> > matb;
typedef vector<string> vst;
typedef pair<lli,lli> pll;
typedef pair<double,double> pdd;
typedef vector<pll> vec;

lli n;
vec rc;
mat dp;

lli solve(lli x,lli y){
    if(x == y) return dp[x][y] = 0;
    if(dp[x][y]) return dp[x][y];
    lli ret = 1ll << 61;
    for(lli i = x;i < y;i++){
        ret = min(ret,solve(x,i) + solve(i+1,y) + rc[i].second*rc[x].first*rc[y].second);
    }
    return dp[x][y] = ret;
}


int main(){
    cin >> n;
    rc = vec(n);
    dp = mat(n,vll(n));
    for(lli i = 0;i < n;i++) cin >> rc[i].first >> rc[i].second;
    cout << solve(0,n-1) << endl;
    return 0;

}