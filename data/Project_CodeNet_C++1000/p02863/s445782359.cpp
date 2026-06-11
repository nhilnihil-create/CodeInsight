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
using namespace std;
//typedef __int64 LL;
//typedef long long int LL;
typedef vector<int> ivec;
typedef vector<string> svec;
typedef pair<int,int> P;
//typedef pair<LL,LL> PL;

const int MOD=1000000007;

int dpf[3010][3010];
int dpl[3010][3010];
int a[3010],b[3010];
int main(){
	int n,t;cin>>n>>t;
	for(int i=0;i<n;i++)cin>>a[i+1]>>b[i+1];
	
	for(int i=1;i<=n;i++)
	{
		for(int j=0;j<=t;j++)
		{
			if(j<a[i])dpf[i][j]=dpf[i-1][j];
			else dpf[i][j]=max(dpf[i-1][j],dpf[i-1][j-a[i]]+b[i]);
		}
		
	}
	
	for(int i=n;i>=1;i--)
	{
		for(int j=0;j<=t;j++)
		{
			if(j<a[i])dpl[i][j]=dpl[i+1][j];
			else dpl[i][j]=max(dpl[i+1][j],dpl[i+1][j-a[i]]+b[i]);
		}
	}
	int ans=0;
	for(int i=1;i<=n;i++)
	{
		for(int s=0;s<=t-1;s++)
		{
			
			ans=max(ans,dpf[i-1][s]+dpl[i+1][t-1-s]+b[i]);
		}
	}
	cout<<ans<<"\n";
	return 0;
}