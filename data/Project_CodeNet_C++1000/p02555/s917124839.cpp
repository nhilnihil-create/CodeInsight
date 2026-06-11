#include <bits/stdc++.h>
#define rep(i,n) for(long long i=0; i<n; i++)
#define Rep(i,n) for(long long i=1; i<n; i++)
#define ll long long
#include <math.h>
#include <cmath>
#include <iomanip>
#include <iostream>
#include <numeric>
#include <queue>
#include <set>
#include <vector>


using namespace std;
#define PI acos(-1)
using P =pair<ll,ll>;


ll m=1000000007;

int mod=1e9+7;
int dp[2000+4];

int main()
{
 int x;
	   	cin>>x;
	   	
	   	dp[0]=1;
	  	for(int sum=0; sum<=x; sum++){
	  		for(int coin =3;coin<=sum;coin++){
	  			dp[sum]+=dp[sum-coin];
	  			dp[sum]%=mod;
	  		}
	  	}
	  	cout<<dp[x]<<endl;
	    return 0;
}
 


 

 


