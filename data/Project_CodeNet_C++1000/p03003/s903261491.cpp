#include<iostream>
#include<algorithm>
#include<vector>
#include<string>
#include<utility>
#include<map>
#include<set>
#include<queue>
#include<math.h>
using namespace std;
#define N (1000000000+7)
#define INF 1e16
typedef long long ll;
typedef pair<ll,ll> P;

ll dp[2010][2010];
int main(void){
    int n,m;
    cin>>n>>m;
    vector<int>s(n),t(m);
    for(int i=0;i<n;i++)cin>>s[i];
    for(int i=0;i<m;i++)cin>>t[i];
    for(int i=0;i<=n;i++)dp[i][0]=1;
    for(int i=0;i<=m;i++)dp[0][i]=1;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            if(s[i-1]==t[j-1])
                dp[i][j]=(dp[i-1][j]+dp[i][j-1])%N;
            else{
                dp[i][j]=
                    ((dp[i-1][j]+dp[i][j-1])%N-dp[i-1][j-1]+N)%N;
            }
        }
    }
    cout<<dp[n][m]<<endl;
    return 0;
}
