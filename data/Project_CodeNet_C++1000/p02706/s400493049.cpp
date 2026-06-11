#include <stdlib.h> 
#include <stdio.h>
#include <iostream>
#include <string.h>
#include <math.h>

using namespace std; 

int main()
{
	int n,m,tdays = 0;
	
	cin>>n>>m;
	
	int days[m];
	
	for(int i = 0; i < m ; i++)
		cin>>days[i];
		
	for(int i = 0; i < m; i++)
		tdays = tdays + days[i];
	
	if(tdays > n) cout<<"-1";
	if(tdays == n) cout<<"0";
	if(tdays < n) cout<< n - tdays;
	
	return 0;
}
