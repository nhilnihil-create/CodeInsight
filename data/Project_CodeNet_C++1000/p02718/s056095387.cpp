#include<iostream>
#include<stdio.h>
#include<cstring>
#include<vector>
#include<set>
#include<map>
#include<algorithm>
#include<math.h>
#define ll long long int
#define d double 
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false); 
    cin.tie(NULL);   
	
	int n,m;
	cin>>n>>m;
	int a[n];
	int i;
	int s=0;
	for(i=0;i<n;i++)
	{
		
		cin>>a[i];
		s=s+a[i];
		
	} 
 
   float z=4*m;
   float x=(1/z)*s;
   
   int count=0;
   for(i=0;i<n;i++)
   {
   	
   	  if(a[i]>=x)
   	  {
   	  	count++;
   	  	
	  }
   	
   }


    if(count>=m)
	{
		
	 cout<<"Yes"<<endl;	
		
	}   
	
	else 
	{
		cout<<"No"<<endl;
		
	}
    
   
    return 0;
}
    