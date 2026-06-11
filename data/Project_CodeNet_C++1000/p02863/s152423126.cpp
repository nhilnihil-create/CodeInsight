#include<iostream>
#include<algorithm>
#include<math.h>
#include<cstdio>
#include<string>
#include<string.h>
#include<list>
#include<queue>
#include<sstream>
#include<vector>
#include<set>
#include<map>
#include<deque>
#include<stack>
using namespace std;
#define debug(x) cout<<"###"<<x<<"###"<<endl;
const int INF=0x3f3f3f3f,MAXN=3e3+5;
typedef long long ll;
int w[MAXN],v[MAXN];
int dp[MAXN][MAXN*2];
struct Node{
	int w,v;
}node[MAXN];
bool cmp(Node a,Node b){
	return a.w<b.w;
}
int main(){
	int n,t;
	cin>>n>>t;
	memset(dp,0,sizeof(dp));
	for(int i=1;i<=n;i++){
		scanf("%d%d",&node[i].w,&node[i].v);
	}
	sort(node+1,node+1+n,cmp);
	for(int i = 1; i <= n; i++){              
        for(int j=1;j<=t+node[i].w-1; j++){
        	if(j<node[i].w){
        		dp[i][j]=dp[i-1][j];
			}
			else{
				 dp[i][j] =max(dp[i-1][j], dp[i-1][j-node[i].w] + node[i].v);
			} 
        }
    }
    int ans=0;
    for(int i=1;i<=n;i++){
    	ans=max(dp[i][t+node[i].w-1],ans);
	}
	cout<<ans<<endl;
	return 0;
}