#include <iostream>
#include<string.h>
#include<algorithm>
#include<bits/stdc++.h>
using namespace std;


int main()
{
    int t,count=0,x;
    cin>>t;
    for(int i=1;i<=t;i++)
    {
    	cin>>x;
    	if(i%2!=0&&(x)%2!=0)
    	{
    		
    			count++;
    			
			
		}
	}
	cout<<count;
    return 0;
}