#include<iostream>
#include<stdio.h>
#include<vector>
#include<set>
#include<map>
#include<algorithm>
#include<math.h>
#include<cstring>
using namespace std;
 
int main()
{
	
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int k,a,b;
    cin>>k>>a>>b;
    int i=0;
    for(i=a;i<=b;i++)
    {
    	
    	if(i%k==0)
    	{
    		
    		cout<<"OK"<<endl;
    		return 0;
    		
		}
    	
    	
    	
	}
	
	
	if(i>=b)
	{
		
		cout<<"NG"<<endl;
		
	}
	
    
    
    
    
    return 0;
    
}
    