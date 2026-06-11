#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define pi 3.141592653589793238
#define fast ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define MOD 1000000007
int main()
{
       fast;
       ll n,d,cnt=0,sum;
       cin>>n>>d;
       ll arr[n][d];
       for(int i=0;i<n;i++)
    		for(int j=0;j<d;j++)
    			cin>>arr[i][j];
    	for(int i=0;i<n;i++){
    		for(int j=i+1;j<n;j++){
    			sum=0;
    			for(int k=0;k<d;k++)
    				sum+=(arr[i][k] - arr[j][k])*(arr[i][k] - arr[j][k]);
    			// cout<<sum<<endl;
    			if(floor(sqrt(sum))==ceil(sqrt(sum)))
    				cnt++;
    		}
    	}
       cout<<cnt;
       return 0;
}
