#include<iostream>
#include<vector>
#include<algorithm>
#include<cctype>
#include<utility>
#include<string>
#include<cmath>
#include<cstring>

#define REP(i, n) for(int i = 0;i < n;i++)
#define REPR(i, n) for(int i = n;i >= 0;i--)
#define FOR(i, m, n) for(int i = m;i < n;i++)
#define FORR(i, m, n) for(int i = m;i >= n;i--)
#define SORT(v, n) sort(v, v+n);
#define VSORT(v) sort(v.begin(), v.end());
#define llong long long
#define pb(a) push_back(a)
#define INF 1000000000
using namespace std;
typedef pair<int, int> P;
typedef pair<llong, llong> LP;
typedef pair<int, P> PP;
typedef pair<llong, LP> LPP;



int dp[22][50010];

int main(){

   REP(i,22){
       REP(j,50010){
           dp[i][j] = INF;
       }
   }

    int n,m;
    cin >> n >> m;
    vector<int> c(m,0);
    REP(i,m){
        cin >> c[i];
        //cout << c[i] << endl;
    }

    //dp[i][j]:i番目までを使って総和がjとなるような枚数の最小

    dp[0][0] = 0;//0番目までで総和が0の枚数
    

    for(int i = 1;i <= c.size();i++){
        //cout << c[i-1] << endl;
        for(int j = 0;j <= n;j++){
            
            if(c[i-1] > j){//c[i]を使えない場合
                dp[i][j] = dp[i-1][j];
                //cout << "a" << " " << j << " " << dp[i][j] << endl;
            }else{//c[i]を使う場合
                dp[i][j] = min(dp[i-1][j],dp[i][j-c[i-1]]+1);
                //cout << "b" << " " << j << " " << dp[i][j] << endl;
            }
        }
        //cout << endl;
    }

    cout << dp[c.size()][n] << endl;   

    return 0;
}
