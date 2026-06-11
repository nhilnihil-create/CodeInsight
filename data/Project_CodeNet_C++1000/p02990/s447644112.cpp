#include <bits/stdc++.h>
using namespace std;
#define fi first
#define endl "\n"
#define se second
#define ll long long
#define inf 0x3f3f3f3f
#define fast    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
const int N = 2e6+5;
const ll mod =   1e9+7;
ll n,k,ncr[2005][2005];
int main()
{  fast
cin>>n>>k;
for(int i=0;i<=n;i++){
	ncr[i][0]=1;
	for(int j=1;j<=i;j++)
	ncr[i][j]=(ncr[i-1][j]+ncr[i-1][j-1])%mod;
}
for(int i=1;i<=k;i++){
	cout<<ncr[n-k+1][i]*ncr[k-1][i-1]%mod<<endl;
}
}