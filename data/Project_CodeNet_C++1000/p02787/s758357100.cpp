#include<iostream>
#include<algorithm>
#include<vector>
#include<string>
#include<cmath>
#include<cstdio>
#include<queue>
#include<deque>
#include<map>
#include<stack>
#include<set>
#include<utility>
using namespace std;
typedef pair<int,int> ii;
typedef long long ll;
typedef pair<ll,ii> P;
typedef unsigned long long int ull;
const int MOD=1e9+7;
int dy[]={1,0,-1,0};
int dx[]={0,1,0,-1};
const int MAXN=100000;
const int MAXE=100000;
const int MAXV=10000;
const ll INF=2e9;

int main(){
    int h,n;cin>>h>>n;
    vector<int> a(n),b(n);
    for(int i=0;i<n;i++) cin>>a[i]>>b[i];
    int dp[n+1][20001];
    for(int i=0;i<=n;i++){
        for(int j=0;j<=20000;j++){
            dp[i][j]=INF;
        }
    }
    dp[0][0]=0;
    for(int i=0;i<n;i++){
        for(int j=0;j<=20000;j++){
            dp[i+1][j]=dp[i][j];
            if(j>=a[i]) dp[i+1][j]=min(dp[i+1][j],dp[i+1][j-a[i]]+b[i]);
        }
    }
    int ans=INF;
    for(int j=h;j<=20000;j++){
        ans=min(ans,dp[n][j]);
    }
    cout<<ans<<endl;
    return 0;
}