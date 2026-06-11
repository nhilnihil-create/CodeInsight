#include<iostream>
#include<stdio.h>
#include<vector>
#include<set>
#include<map>
#include<algorithm>
#include<math.h>
#include<cstring>
#define ll long long int
using namespace std;
 
int main()
{
	
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
     
     int n,m;
     cin>>n>>m;
     int a[m];
     int i;
     int s=0;
     for(i=0;i<m;i++)
     {
     	
     	cin>>a[i];
     	s=s+a[i];
     	
	 }
	 
	 int h=n-s;
	 
	 if(h<-1)
	 {
	 	
	 	cout<<"-1"<<endl;
	 	
	 }
	 
	 else
	 {
	 	
	 	cout<<h<<endl;
	 	 
	 }
 
 
 
    
    return 0;
}
    
    
    