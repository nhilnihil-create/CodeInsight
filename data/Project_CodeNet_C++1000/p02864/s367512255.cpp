#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <stack>
#include <queue>
#include <set>
#include <map>
#include <iomanip>
#include<cmath>
using namespace std;
//typedef __int64 LL;
typedef long long int LL;
typedef vector<int> ivec;
typedef vector<string> svec;
typedef pair<int,int> P;
//typedef pair<LL,LL> PL;

const int MOD=1000000007;
LL INF=1001001001001001;

LL h[310];
LL dp[310][310];
int main(){
	LL n,k;cin>>n>>k;
	for(LL i=1;i<=n;i++)cin>>h[i];
	h[0]=0,h[n+1]=0;
	for(int i=1;i<=n+1;i++)
	{
		for(int j=0;j<=k;j++)
		{
			LL po=INF;
			for(int k=0;k<=j;k++)
			{
				if(i-1-k<0)continue;
				po=min(po,dp[i-1-k][j-k]+abs(h[i-1-k]-h[i]));	
			}
			dp[i][j]=po;
		}
	}
	cout<<dp[n+1][k]/2<<"\n";	
	return 0;
}