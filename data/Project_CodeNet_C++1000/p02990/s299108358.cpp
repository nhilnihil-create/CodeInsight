#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define pi 3.141592653589793238
#define fast ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define MOD 1000000007
int main()
{
       fast;
       ll n,k;
       cin>>n>>k;
       ll arr[2005][2005];
       memset(arr,0,sizeof(arr));
       arr[0][0]=1;
       for(int i=0;i<=n;i++)
    	arr[i][0]=1;
       for(int i=1;i<=n;i++)
    		for(int j=1;j<=i;j++)
    			arr[i][j]=(arr[i-1][j-1]%MOD+arr[i-1][j]%MOD)%MOD;
    	for(int i=1;i<=k;i++)
    		cout<<(arr[n-k+1][i]%MOD*arr[k-1][i-1]%MOD)%MOD<<endl;
       return 0;
}