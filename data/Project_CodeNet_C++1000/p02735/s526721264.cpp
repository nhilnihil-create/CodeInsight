#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;

const int N=105;
char s[N][N];
int dp[N][N];


void init();
void work();
int ca=1;
int main(){
//    freopen("in.txt","r",stdin);
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
//    init();
//    int T;cin>>T;
//    while(T--)
    work();
    return 0;
}
void work(){
    int n,m;cin>>n>>m;
    for(int i=1;i<=n;i++) cin>>s[i]+1;
    memset(dp,0x3f,sizeof dp);
    if(s[1][1]=='#') dp[1][1]=1;
    else dp[1][1]=0;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            if(i==1&&j==1) continue;
            if(i>1){
                if(s[i][j]!=s[i-1][j]){
                    if(s[i][j]=='#') dp[i][j]=min(dp[i][j],dp[i-1][j]+1);
                    else dp[i][j]=min(dp[i][j],dp[i-1][j]);
                }else dp[i][j]=min(dp[i][j],dp[i-1][j]);
            }
            if(j>1){
                if(s[i][j]!=s[i][j-1]){
                    if(s[i][j]=='#') dp[i][j]=min(dp[i][j],dp[i][j-1]+1);
                    else dp[i][j]=min(dp[i][j],dp[i][j-1]);
                }else dp[i][j]=min(dp[i][j],dp[i][j-1]);
            }
        }
    }
    cout<<dp[n][m];
}
