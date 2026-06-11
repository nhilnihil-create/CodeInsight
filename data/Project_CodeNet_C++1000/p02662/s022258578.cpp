#include<bits/stdc++.h>
using namespace std;

#define     MX        2000005
#define     mod       998244353
#define     ll        long long
#define     ld        double
#define     mem(a,b)  memset(a,b,sizeof(a))
#define     fast()    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define     F         first
#define     S         second
#define     mp        make_pair
#define     inf       2e18
#define     PI        acos(-1.0)

int dx[] = {+1,-1,0,0};
int dy[] = {0,0,+1,-1};

int n,s;
int a[3005];
int dp[2][3005];

int main(){
    fast();
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    cin>>n>>s;
    for(int i=1;i<=n;i++) cin>>a[i];
    int cur=0;
    dp[cur][0]=1;
    for(int i=n;i>=1;i--){
        for(int j=0;j<=s;j++) dp[cur^1][j]=0;
        for(int j=0;j<=s;j++) dp[cur^1][j]=(2LL*dp[cur][j])%mod;
        for(int j=a[i];j<=s;j++) dp[cur^1][j]= (dp[cur^1][j]+dp[cur][j-a[i]])%mod;
        for(int j=0;j<=s;j++) dp[cur][j]= dp[cur^1][j];
        cur^=1;
    }
    cout<<dp[cur][s]<<endl;
    return 0;
}
