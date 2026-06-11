#include<bits/stdc++.h>
#define int long  long 
#define ar array

using namespace std ;
const int N =1e7 +5 ;
int f[N] ;
                                                                                              
signed main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL) ;

	int n ; 
	cin>>n;
	for(int i=1;i<N;i++)
		for(int j=i;j<N;j+=i) f[j]++; 
	int ans=0;
	for(int i=1;i<=n;i++) ans=ans+f[i]*i;
	cout<<ans<<endl;

}






