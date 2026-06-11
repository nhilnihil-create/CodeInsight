#include <bits/stdc++.h>
using namespace std;
long long v[2005][2005],mod=1e9+7,n,k;
int main(){
	cin>>n>>k;
	v[0][0]=1;
	for(int i=1;i<=n;i++){
		v[i][0]=1;
		for(int j=1;j<=i;j++)
			v[i][j]=(v[i-1][j-1]+v[i-1][j])%mod;
	}
	for(int i=1;i<=k;i++)
		cout<<v[n-k+1][i]*v[k-1][i-1]%mod<<endl;
	return 0;
}