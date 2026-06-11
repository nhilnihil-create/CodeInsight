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
    cin>>N;
    vector<string> dp[14][14];
    dp[0][0].push_back("a");
    rep(i, N) rep(j, 11){
        rep(k, dp[i][j].size()){
            rep(l, j+1){
                char b='a'+l;
                dp[i+1][j].push_back(dp[i][j][k]+b);
            }
            char b='a'+j+1;
            dp[i+1][j+1].push_back(dp[i][j][k]+b);
        }
    }
    vector<string> ans;
    rep(i, 11){
        rep(j, dp[N-1][i].size()){
            ans.push_back(dp[N-1][i][j]);
        }
    }
    sort(all(ans));
    rep(i, ans.size()){
        cout<<ans[i]<<endl;
    }
    return 0;
}
