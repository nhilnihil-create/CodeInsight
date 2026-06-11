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

#define rep(i,n) for(int i=0, i##_len=(n); i<i##_len; ++i)
#define all(x) (x).begin(),(x).end()
#define MEMSET(v, h) memset((v), h, sizeof(v))
typedef long long ll;

using namespace std;

int main(void){
    ll N, K;
    ll H[400];
    MEMSET(H, 0);
    cin>>N>>K;
    rep(i, N) cin>>H[i+1];
    ll dp[400][400];
    rep(i, N) rep(j, K+1) dp[i+1][j]=9000000000000;
    rep(i, N) rep(j, K+1){
        if(i==0&&j!=0) break;
        
    
        //dp[i+1][j]=min(dp[i+1][j], dp[i][j]+max(H[i+1]-H[i], (ll)0));
        rep(t, K-j+1){
            if(i+t==N){
                dp[N][j+t-1]=min(dp[i][j], dp[N][j+t-1]);
                break;
            }
            dp[i+t+1][j+t]=min(dp[i+t+1][j+t], dp[i][j]+max((ll)0, H[i+t+1]-H[i]));
            
            /*cout<<i<<" "<<j<<" " <<t<<endl;
            rep(l, N+1){
                rep(m, K+1) cout<<dp[l][m]<<" ";
                cout<<endl;
            }
            cout<<endl;*/
        }
    }
    ll Minim=90000000000000;
    rep(i, K+1){
        Minim=min(Minim, dp[N][i]);
    }
    /*rep(i, N+1){
        rep(j, K+1) cout<<dp[i][j]<<"\t\t";
        cout<<endl;
    }*/
    cout<<Minim<<endl;
    return 0;
}
