#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <string>
#include <cstring>
#include <utility>
#include <set>
#include <stack>
#include <climits>
#include <cmath>

#define rep(i,n) for(int i=0, i##_len=(n); i<i##_len; ++i)
#define rep1(i,n) for(int i=1, i##_len=(n); i<=i##_len; ++i)
#define reps(i,s,n) for(int i=s, i##_len=(n); i<i##_len; ++i)
#define all(x) (x).begin(),(x).end()
#define MEMSET(v, h) memset((v), h, sizeof(v))
typedef long long ll;
const char sp = ' ';


using namespace std;

int main(void){
    ll N;
    vector<string> dp[15][15];
    cin>>N;
    dp[0][1].push_back("a");
    rep(i, N) rep(j, 15){
        rep(u, dp[i][j].size()){
            string str="a";
            rep(k, j){
                dp[i+1][j].push_back(dp[i][j][u]+str);
                str[0]++;
            }
            dp[i+1][j+1].push_back(dp[i][j][u]+str);
        }
    }
    vector<string> ans;
    rep(j, 15){
        rep(u, dp[N-1][j].size()){
            ans.push_back(dp[N-1][j][u]);
        }
    }
    sort(all(ans));
    rep(i, ans.size()){
        cout<<ans[i]<<endl;
    }
    return 0;
}
