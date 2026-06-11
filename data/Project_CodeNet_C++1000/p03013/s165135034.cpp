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
    int n,m;cin>>n>>m;
    ll dp[n+1];
    for(int i=0;i<=n;i++) dp[i]=0;
    dp[0]=1;
    for(int i=0;i<m;i++){
        int a;cin>>a;
        dp[a]=-1;
    }
    for(int i=1;i<=n;i++){
        if(dp[i]==-1) continue;
        if(dp[i-1]!=-1) dp[i]+=dp[i-1];
        if(i-2>=0&&dp[i-2]!=-1) dp[i]+=dp[i-2];
        dp[i]%=MOD;
    }
    cout<<dp[n]<<endl;
    return 0;
}