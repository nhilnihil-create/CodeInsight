#include"bits/stdc++.h"
using namespace std;
typedef long long ll;
#define int ll
const int mod=1e9+7;
int C[5000][5000];
void comp()
{
	for(int i=0;i<5000;i++)
	{
		C[i][0]=1;
	}
	for(int i=1;i<5000;i++)
		for(int j=1;j<5000;j++)
			C[i][j]=(C[i-1][j-1]+C[i-1][j])%mod;
}
int32_t main()
{
	#ifndef ONLINE_JUDGE
	freopen("in","r",stdin);
	freopen("out","w",stdout);
	#endif
	int n,k;
	cin>>n>>k;

	comp();
	//cout<<C[2][1]*C[3][2]<<"\n";
	for(int i=1;i<=k;i++)
	{
		//cout<<k-1<<" "<<i-1<<" "<<n-k+i<<" "<<i<<"\n";
		cout<<(C[k-1][i-1]*C[n-k+1][i])%mod<<"\n";
	}


}