#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
#define N 3000
#define MOD 998244353
ll f[N+10][N+10];
int A[N+10];
int ans=0;
void solve()
{
	int n,s;
	cin>>n>>s;
	for (int i=1;i<=n;i++)
		cin>>A[i];
	f[0][0]=1;
	for (int i=1;i<=n;i++)
		for (int j=0;j<=3000;j++)
		{
				if (A[i]<=j)
					f[i][j]=(f[i-1][j]*2+f[i-1][j-A[i]])%MOD;
				else
					f[i][j]=(f[i-1][j]*2)%MOD;				
		}
	
	cout<<f[n][s]<<endl;
}



int main() 
{
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
//	int t;
//	cin>>t;
//	while (t--) 
	solve();
	return 0;
}