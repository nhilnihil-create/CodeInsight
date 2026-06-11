#if 0
dp[i][j] = min( dp[i???1][j] , dp[i][j???c[i]]+1 )
					||
dp[i] = min ( dp[j] , dp[j-c[i]]+1 )					
#endif

#include <iostream>  
using namespace std;  
 
  
const int MAX_NUM = 50010;  
const int MAX_WEIGHT = 50000+20;  

   
int c[MAX_NUM];  
 
int dp[MAX_WEIGHT];  
  

void Solve( int n, int m )  
{     
	for (int i=0; i<m; i++ )  
	{  
		for (int j=c[i]; j<=n; j++)  
		{   
			dp[j] = min(dp[j],dp[j-c[i]]+1);      	         
		}  
	}  
	cout << dp[n] << endl;  
}  

int main()  
{    
	int n, m;  
	cin >> n >> m;        
	for (int i=0; i<m; i++ )  
	{  
		cin >> c[i];  
	}  
	for (int i=1; i<=n; i++)
	{
		dp[i] = 50000+10;
	}
	Solve( n, m );  
 
	return 0;  
}  