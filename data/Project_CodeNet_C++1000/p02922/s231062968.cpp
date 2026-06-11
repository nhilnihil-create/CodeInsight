#include <stdlib.h> 
#include <stdio.h>
#include <iostream>
#include <string.h>
#include <math.h>

using namespace std; 

int main()
{
	int a,b;
	
  	cin>>a>>b;
  	
  	int ans;
  	
  	ans = ( b - 1 + a - 2) / ( a - 1);
  	
  	cout<<ans;
  	
	return 0;
}
