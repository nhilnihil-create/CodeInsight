#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

using ll = long long;

ll dp[310][310][310] = {};
ll mi[310][310][310] = {};
ll inf = 1e18;

int main(){
    int N,K;
    cin >> N >> K;
    vector<ll> H(N+1,0),L(N+1,0);
    for(int i=1;i<=N;i++){
        cin >> H[i];
        L[i] = H[i];
    }
    sort(L.begin(),L.end());
    L.erase(unique(L.begin(),L.end()),L.end());
    int M = L.size()-1;
    for(int i=0;i<=N;i++) for(int j=0;j<=M;j++) for(int k=0;k<=K;k++){
        dp[i][j][k] = inf;
        mi[i][j][k] = inf;
    }
    dp[0][0][0] = 0;
    mi[0][0][0] = 0;
    for(int i=1;i<=N;i++){
        for(int j=0;j<=M;j++) for(int k=0;k<=K;k++){
            if(H[i]==L[j]){
                for(int pj=0;pj<=M;pj++){
                    ll cost = (pj>=j? 0:L[j]-L[pj]);
                    dp[i][j][k] = min(dp[i][j][k],dp[i-1][pj][k]+cost);
                }
            }else if(k!=K){
                dp[i][j][k+1] = min(dp[i][j][k+1],mi[i-1][j][k]);
                if(j!=0) dp[i][j][k+1] = min(dp[i][j][k+1],dp[i][j-1][k+1]+L[j]-L[j-1]);
            }
        }
        for(int j=M-1;j>=0;j--) for(int k=0;k<=K;k++){
            mi[i][j][k] = min(mi[i][j+1][k],dp[i][j][k]);
        }
    }
    ll ans = inf;
    for(int j=0;j<=M;j++) for(int k=0;k<=K;k++) ans = min(ans,dp[N][j][k]);
    cout << ans << endl;
}